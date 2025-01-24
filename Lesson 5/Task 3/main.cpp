#include <iostream>
#include <string>

template<typename T>
class MyVector {
private:
	T* elements;
	unsigned size_;
	unsigned capacity_;
public:
	MyVector() : elements{ new T[1]{} }, size_{ 0 }, capacity_{ 1 } {}
	~MyVector() {
		delete[] elements;
	}
	void push_back(T value) {
		if (size_ == capacity_) {
			T* tmp = new T[capacity_];
			for (unsigned i = 0; i < capacity_; i++) {
				tmp[i] = elements[i];
			}
			delete[] elements;
			elements = new T[capacity_ * 2];
			for (unsigned i = 0; i < capacity_; i++) {
				elements[i] = tmp[i];
			}
			delete[] tmp;
			capacity_ *= 2;
		}
		elements[size_++] = value;
	}
	T& at(unsigned index) {
		if (index >= size_) {
			throw std::runtime_error("index out of range");
		}
		return elements[index];
	}
	unsigned size() const {
		return size_;
	}
	unsigned capacity() const {
		return capacity_;
	}
	void display() const {
		for (unsigned i = 0; i < size_; i++) {
			std::cout << elements[i] << ' ';
		}
	}
};

int main() {
	MyVector<double> double_vector;
	std::cout << "double_vector:" << std::endl;
	std::cout << "size = " << double_vector.size() << std::endl;
	std::cout << "capacity = " << double_vector.capacity() << std::endl;
	double_vector.push_back(5.5);
	double_vector.push_back(10.25);
	double_vector.push_back(1.333);
	double_vector.push_back(2.0);
	double_vector.push_back(6);
	double_vector.push_back(89.123);
	std::cout << "after adding 6 elements" << std::endl;
	std::cout << "size = " << double_vector.size() << std::endl;
	std::cout << "capacity = " << double_vector.capacity() << std::endl;
	double_vector.at(3) = 7.7;
	std::cout << "double_vector.at(3) = " << double_vector.at(3) << std::endl;
	double_vector.display();
	MyVector<std::string> string_vector;
	std::cout << "\n\nstring_vector:" << std::endl;
	std::cout << "size = " << string_vector.size() << std::endl;
	std::cout << "capacity = " << string_vector.capacity() << std::endl;
	string_vector.push_back("one");
	string_vector.push_back("two");
	string_vector.push_back("three");
	std::cout << "after adding 3 elements" << std::endl;
	std::cout << "size = " << string_vector.size() << std::endl;
	std::cout << "capacity = " << string_vector.capacity() << std::endl;
	string_vector.at(1) = "new_value";
	std::cout << "string_vector.at(1) = " << string_vector.at(1) << std::endl;
	string_vector.display();
	try {
		std::cout << "\n\ntrying wrong index" << std::endl;
		double_vector.at(20);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}