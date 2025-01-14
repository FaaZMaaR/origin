﻿#include <iostream>

class smart_array {
	private:
		int* array;
		unsigned size;
		unsigned last;
	public:
		smart_array(unsigned array_size) : size{ array_size }, last{ 0 } {
			array = new int[size];
		}
		void add_element(int value) {
			if (last == size) {
				throw std::runtime_error("smart_array is full!");
			}
			array[last++] = value;
		}
		int get_element(unsigned index) {
			if (index >= size) {
				throw std::runtime_error("index out of range!");
			}
			return array[index];
		}
		~smart_array() {
			delete[] array;
		}
};

void test_func() {
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}

int main() {
	test_func();
}