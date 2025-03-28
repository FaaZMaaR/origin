#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

void inc_client_count(int count, int& client_count) {
    for (int i = 0; i < count; ++i) {
        ++client_count;
        std::this_thread::sleep_for(1s);
    }    
}

void decr_client_count(int& client_count) {
    while (client_count == 0) {
        std::this_thread::sleep_for(2s);
    }
    while (client_count > 0) {        
        --client_count;
        std::this_thread::sleep_for(2s);
    }
}

void print_client_count(int& client_count) {
    while (client_count == 0) {
        std::this_thread::sleep_for(1s);
    }
    while (client_count > 0) {
        std::cout << "clients remain: " << client_count << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main() {
    int client_count = 0;
    std::thread client{ inc_client_count, 10, std::ref(client_count) };
    std::thread queue_operator{ decr_client_count, std::ref(client_count) };
    print_client_count(client_count);
    client.join();
    queue_operator.join();
}