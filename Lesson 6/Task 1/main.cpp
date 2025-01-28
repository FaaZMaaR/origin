#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void unique_vector(std::vector<T>& vector) {
    std::sort(vector.begin(), vector.end());
    auto duplicates_iterator = std::unique(vector.begin(), vector.end());
    vector.erase(duplicates_iterator, vector.end());
}

template<typename T>
void display_vector(const std::vector<T>& vector) {
    for (const auto& value : vector) {
        std::cout << value << ' ';
    }
}

int main() {
    std::vector<int> int_vector{ 1,1,2,5,6,1,2,4 };
    std::cout << "[IN]: ";
    display_vector(int_vector);
    unique_vector(int_vector);
    std::cout << "\n[OUT]: ";
    display_vector(int_vector);
}