#include <iostream>
#include <vector>
#include <algorithm>

struct get_sum {
	int sum{ 0 };
	void operator()(int value) {
		if (value % 3 == 0) {
			sum += value;
		}
	}
};

struct get_count {
	int count{ 0 };
	void operator()(int value) {
		if (value % 3 == 0) {
			++count;
		}
	}
};

template<typename T>
void display_vector(const std::vector<T>& vector) {
	for (const auto& value : vector) {
		std::cout << value << ' ';
	}
}

int main() {
	std::vector<int> int_vector{ 4,1,3,6,25,54 };
	auto sum = std::for_each(int_vector.begin(), int_vector.end(), get_sum());
	auto count = std::for_each(int_vector.begin(), int_vector.end(), get_count());
	std::cout << "[IN]: ";
	display_vector(int_vector);
	std::cout << "\n[OUT]: get_sum() = " << sum.sum << std::endl;
	std::cout << "[OUT]: get_count() = " << count.count << std::endl;
}