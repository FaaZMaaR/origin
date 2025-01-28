#include <iostream>
#include <set>
#include <list>
#include <vector>

template<typename Iter>
void print_container(Iter begin, Iter end) {
    for (; begin != end; ++begin) {
        std::cout << *begin << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set.begin(), test_set.end());

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list.begin(), test_list.end());

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector.begin(), test_vector.end());
}