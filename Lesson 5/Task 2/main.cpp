#include <iostream>
#include <set>

int main() {	
	std::cout << "[IN]:" << std::endl;
	int numbers_count{ 0 };
	int number{ 0 };
	std::cin >> numbers_count;
	std::set<int, std::greater<int>> int_set;
	for (int i = 0; i < numbers_count; i++) {
		std::cin >> number;
		int_set.insert(number);
	}
	std::cout << "[OUT]:" << std::endl;
	for (const auto& elem : int_set) {
		std::cout << elem << std::endl;
	}
}