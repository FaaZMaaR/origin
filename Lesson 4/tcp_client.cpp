#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <string>

class TcpClient {
private:
    WSAData wsadata;
    SOCKET mSocket;
    sockaddr_in server_addr{}, client_addr{};
    char* buf = new char[32];
    std::string message;
    int port = 5555;
public:
    TcpClient(const std::string& msg) : message{ msg } {
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
    }
    ~TcpClient() {
        closesocket(mSocket);
        WSACleanup();
        delete[] buf;
    }

    void send_data() { 
        int iResult = connect(mSocket, (SOCKADDR*)&server_addr, sizeof(server_addr));
        if (iResult == SOCKET_ERROR) {
            std::cout << "connection failed" << std::endl;
            iResult = closesocket(mSocket);
            if (iResult == SOCKET_ERROR) {
                std::cout << "closesocket failed" << std::endl;
            }
            WSACleanup();
            return;
        }

        std::cout << "Connected to server." << std::endl;

        send(mSocket, message.c_str(), message.size(), 0);
        int size_data = recv(mSocket, buf, 32, 0);
        if (size_data > 0) {
            std::cout << buf << std::endl;
        }
        else {
            std::cout << WSAGetLastError() << std::endl;
        }
    }
};

int main() {
    std::string message;
    std::cout << "Enter message: ";
    std::cin >> message;
    TcpClient client(message);
    client.send_data();
}