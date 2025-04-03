#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

using namespace std::chrono_literals;

void inc_client_count_relaxed(int count, std::atomic<int>& client_count) {
    for (int i = 0; i < count; ++i) {
        client_count.fetch_add(1,std::memory_order_relaxed);
        std::this_thread::sleep_for(1s);
    }
}

void decr_client_count_relaxed(std::atomic<int>& client_count) {
    while (client_count.load(std::memory_order_relaxed) == 0) {
        std::this_thread::sleep_for(2s);
    }
    while (client_count.load(std::memory_order_relaxed) > 0) {
        client_count.fetch_sub(1,std::memory_order_relaxed);
        std::this_thread::sleep_for(2s);
    }
}

void print_client_count_relaxed(std::atomic<int>& client_count) {
    while (client_count.load(std::memory_order_relaxed) == 0) {
        std::this_thread::sleep_for(1s);
    }
    while (client_count.load(std::memory_order_relaxed) > 0) {
        std::cout << "clients remain: " << client_count.load(std::memory_order_relaxed) << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

void inc_client_count_seq_cst(int count, std::atomic<int>& client_count) {
    for (int i = 0; i < count; ++i) {
        client_count.fetch_add(1);
        std::this_thread::sleep_for(1s);
    }
}

void decr_client_count_seq_cst(std::atomic<int>& client_count) {
    while (client_count.load() == 0) {
        std::this_thread::sleep_for(2s);
    }
    while (client_count.load() > 0) {
        client_count.fetch_sub(1);
        std::this_thread::sleep_for(2s);
    }
}

void print_client_count_seq_cst(std::atomic<int>& client_count) {
    while (client_count.load() == 0) {
        std::this_thread::sleep_for(1s);
    }
    while (client_count.load() > 0) {
        std::cout << "clients remain: " << client_count.load() << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main() {
    std::atomic<int> client_count1{ 0 };
    std::thread client1{ inc_client_count_relaxed, 10, std::ref(client_count1) };
    std::thread queue_operator1{ decr_client_count_relaxed, std::ref(client_count1) };
    print_client_count_relaxed(client_count1);
    client1.join();
    queue_operator1.join();

    std::cout << std::endl;

    std::atomic<int> client_count2{ 0 };
    std::thread client2{ inc_client_count_seq_cst, 10, std::ref(client_count2) };
    std::thread queue_operator2{ decr_client_count_seq_cst, std::ref(client_count2) };
    print_client_count_seq_cst(client_count2);
    client2.join();
    queue_operator2.join();
}