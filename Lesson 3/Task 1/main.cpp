#include <iostream>
#include <future>
#include <vector>
#include <random>

template <typename Iter>
void find_min(Iter beg, Iter end, std::promise<Iter> promise) {
    Iter min = beg;
    for (auto i = beg + 1; i != end; ++i) {
        if (*i < *min) {
            min = i;
        }
    }
    promise.set_value(min);
}

template <typename Iter>
void selection_sort(Iter beg, Iter end) {
    for (auto i = beg; i != end; ++i) {
        std::promise<Iter> promise{};
        std::future<Iter> future{ promise.get_future() };
        auto asyncFindMin = std::async(find_min<Iter>, i, end, std::move(promise));
        std::swap(*i, *future.get());
    }
}

int main() {
    std::vector<int> vec(10);
    std::random_device rd{};
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 1000);
    std::generate(vec.begin(), vec.end(), [=]()mutable {return dis(gen); });

    std::cout << "Before sort:" << std::endl;
    for (auto v : vec) {
        std::cout << v << ' ';
    }
    selection_sort(vec.begin(), vec.end());
    std::cout << "\n\nAfter sort:" << std::endl;
    for (auto v : vec) {
        std::cout << v << ' ';
    }
}