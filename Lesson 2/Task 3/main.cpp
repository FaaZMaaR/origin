#include <iostream>
#include <thread>
#include <mutex>

struct Data {
    int intData{};
    std::string stringData{};
    std::mutex mtx{};

    void print() {
        std::cout << intData << ' ' << stringData << std::endl;
    }
};

void swap_lock(Data& data1, Data& data2) {
    std::lock(data1.mtx, data2.mtx);
    std::swap(data1.intData, data2.intData);
    std::swap(data1.stringData, data2.stringData);
    data1.mtx.unlock();
    data2.mtx.unlock();
}
void swap_scoped_lock(Data& data1, Data& data2) {
    std::scoped_lock sl{ data1.mtx, data2.mtx };
    std::swap(data1.intData, data2.intData);
    std::swap(data1.stringData, data2.stringData);
}
void swap_unique_lock(Data& data1, Data& data2) {
    std::unique_lock ul1{ data1.mtx };
    std::unique_lock ul2{ data2.mtx };
    std::swap(data1.intData, data2.intData);
    std::swap(data1.stringData, data2.stringData);
}

int main() {
    Data d1{ 10,"abc" };
    Data d2{ 20,"xyz" };
    std::cout << "Before swap:" << std::endl;
    d1.print();
    d2.print();
    std::thread t1{ swap_lock,std::ref(d1),std::ref(d2) };
    std::thread t2{ swap_lock,std::ref(d1),std::ref(d2) };
    std::thread t3{ swap_lock,std::ref(d1),std::ref(d2) };
    t1.join();
    t2.join();
    t3.join();
    std::cout << "\nAfter swap_lock:" << std::endl;
    d1.print();
    d2.print();
    t1 = std::thread{ swap_scoped_lock,std::ref(d1),std::ref(d2) };
    t2 = std::thread{ swap_scoped_lock,std::ref(d1),std::ref(d2) };
    t3 = std::thread{ swap_scoped_lock,std::ref(d1),std::ref(d2) };
    t1.join();
    t2.join();
    t3.join();
    std::cout << "\nAfter swap_scoped_lock:" << std::endl;
    d1.print();
    d2.print();
    t1 = std::thread{ swap_unique_lock,std::ref(d1),std::ref(d2) };
    t2 = std::thread{ swap_unique_lock,std::ref(d1),std::ref(d2) };
    t3 = std::thread{ swap_unique_lock,std::ref(d1),std::ref(d2) };
    t1.join();
    t2.join();
    t3.join();
    std::cout << "\nAfter swap_unique_lock:" << std::endl;
    d1.print();
    d2.print();
}