#include <iostream>
#include <vector>

template<typename T>
T square(T number) {
	return number * number;
}

template<typename T>
void square(std::vector<T>& vector) {
	for (int i = 0; i < vector.size(); i++) {
		vector[i] = vector[i] * vector[i];
	}
}

template<typename T>
void display_vector(const std::vector<T>& vector) {
	for (const auto& value : vector) {
		std::cout << value << ' ';
	}
}

int main() {
	int number = 4;
	std::cout << "[IN]: " << number << std::endl;
	std::cout << "[OUT]: " << square(number) << std::endl;
	std::vector<int> vector{ -1,4,8 };
	std::cout << "[IN]: ";
	display_vector(vector);
	square(vector);
	std::cout << "\n[OUT]: ";
	display_vector(vector);
}