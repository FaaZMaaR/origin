#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <string>

class TcpServer {
private:
    WSAData wsadata;
    SOCKET mSocket;
    sockaddr_in server_addr{}, client_addr{};
    char* buf = new char[32];
    int port = 5555;
public:
    TcpServer() {
        int iResult = WSAStartup(MAKEWORD(2, 2), &wsadata);
        if (iResult != NO_ERROR) {
            std::cout << "WSAStartup failed" << std::endl;;
            return;
        }

        mSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (mSocket == INVALID_SOCKET) {
            std::cout << "Socket not created" << std::endl;
            WSACleanup();
            return;
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

        if (bind(mSocket, (SOCKADDR*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
            std::cout << "bind failed" << std::endl;
            closesocket(mSocket);
            WSACleanup();
            return;
        }

        if (listen(mSocket, 1) == SOCKET_ERROR) {
            std::cout << "listen failed" << std::endl;
            closesocket(mSocket);
            WSACleanup();
            return;
        }
    }
    ~TcpServer() {
        closesocket(mSocket);
        WSACleanup();
        delete[] buf;
    }

    void receive_and_answer() {
        SOCKET AcceptSocket;
        std::cout << "Waiting for client..." << std::endl;

        AcceptSocket = accept(mSocket, NULL, NULL);
        if (AcceptSocket == INVALID_SOCKET) {
            std::cout << "accept failed" << std::endl;
            closesocket(mSocket);
            WSACleanup();
            return;
        }
        else {
            std::cout << "Client connected." << std::endl;
        }

        int size_data = recv(mSocket, buf, 32, 0);
        if (size_data > 0) {
            std::cout << buf << std::endl;
            std::string answer = "Hello, client!";
            send(mSocket, answer.c_str(), answer.size(), 0);
        }
        else {
            std::cout << WSAGetLastError() << std::endl;
        }
    }
};

int main() {
    TcpServer server;
    server.receive_and_answer();
}