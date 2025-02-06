#include <iostream>
#include <vector>

template<typename T>
void move_vectors(std::vector<T>& lvector, std::vector<T>& rvector) {
    if (&lvector == &rvector) {
        return;
    }
    lvector = std::move(rvector);
}

int main() {
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    move_vectors(two, one);

    for (auto v : one) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
    for (auto v : two) {
        std::cout << v << ' ';
    }
}