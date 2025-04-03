#include <mutex>
#include <thread>
#include <chrono>
#include <vector>
#include <random>
#include "timer.h"

using namespace std::chrono_literals;

class ProgressBar {
private:
    int x, y, progress;

public:
    ProgressBar(int aX, int aY) : x{ aX }, y{ aY }, progress{ 0 } {}

    void print(int color) const {
        consol_parameter::SetPosition(x, y);
        std::cout << "\33[2K\r";
        std::cout << '[';
        consol_parameter::SetColor(color, 0);
        for (int i = 0; i < 25; i++) {
            if (i < progress / 4) {
                std::cout << '\xB2';
            }
            else {
                std::cout << '\xB0';
            }
        }
        consol_parameter::SetColor(7, 0);
        std::cout << ']';
    }

    void setProgress(int percent) {
        progress = percent;
    }
};

class Calculation {
private:
    int goal, threads_count;

    int counter{ 0 };
    std::mutex mtx{};
    std::mt19937 gen{};

    void generateError() {
        std::mt19937 gen;
        gen.seed(std::time(nullptr));
        if (gen() % 10 == 0) {
            throw std::exception{};
        }
    }

    void execute_part(int number) {
        std::unique_lock<std::mutex> ulock{ mtx };
        consol_parameter::SetPosition(0, number * threads_count);
        std::cout << "Thread number: " << number << '\n';
        std::cout << "ID: " << std::this_thread::get_id();
        std::cout << "\n\nStatus: in progress";
        ProgressBar progressBar{ 0,number * threads_count + 2 };
        progressBar.print(3);
        Timer timer{};
        ulock.unlock();
        try {
            for (int i = 0; i < goal / threads_count; ++i) {
                ulock.lock();
                if (gen() % 1000 == 0) {
                    throw std::exception{};
                }
                ++counter;
                progressBar.setProgress(((i + 1) * 100) / (goal / threads_count));
                progressBar.print(3);
                ulock.unlock();
                std::this_thread::sleep_for(100ms);
            }
            ulock.lock();
            consol_parameter::SetPosition(0, number * threads_count + 2);
            std::cout << "\n\33[2K\r";
            std::cout << "Status: completed in " << timer.get_elapsed_time();
            progressBar.print(10);            
        }
        catch (const std::exception& err) {            
            consol_parameter::SetPosition(0, number * threads_count + 2);
            std::cout << "\n\33[2K\r";
            std::cout << "Status: calculation error";
            progressBar.print(4);

        }               
    }

public:
    Calculation(int aGoal, int aThreads) : goal{ aGoal }, threads_count{ aThreads } {
        gen.seed(std::time(nullptr));
    }

    void execute() {
        counter = 0;
        std::vector<std::thread> threads;
        for (int i = 0; i < threads_count; ++i) {            
            threads.push_back(std::thread{&Calculation::execute_part,this,i});
        }
        for (auto& thread : threads) {
            thread.join();
        }
    }
};

int main() {
    /*std::mt19937 gen;
    gen.seed(std::time(nullptr));
    for (int i = 0; i < 100; i++) {
        std::cout << gen() % 100 << std::endl;
    }*/

    Calculation calc{ 1000,4 };
    calc.execute();
}