#include <iostream>
#include <vector>
#include <algorithm>

class MyFunctor {
private:
	int sum;
	int count;
public:
	MyFunctor() : sum{ 0 }, count{ 0 } {}
	void operator()(int value) {
		if (value % 3 == 0) {
			sum += value;
			++count;
		}
	}
	int get_sum() const {
		return sum;
	}
	int get_count() const {
		return count;
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
	auto result = std::for_each(int_vector.begin(), int_vector.end(), MyFunctor());
	std::cout << "[IN]: ";
	display_vector(int_vector);
	std::cout << "\n[OUT]: get_sum() = " << result.get_sum() << std::endl;
	std::cout << "[OUT]: get_count() = " << result.get_count() << std::endl;
}