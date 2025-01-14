#include <iostream>

class smart_array {
private:
	int* array;
	unsigned size;
	unsigned last;
public:
	smart_array(unsigned s) : size{ s }, last{} {
		array = new int[size] {};
	}
	smart_array(const smart_array& sa) : size{ sa.size }, last{ sa.last } {
		array = new int[sa.size];
		for (unsigned i = 0; i < size; i++) {
			array[i] = sa.array[i];
		}
	}
	smart_array& operator=(const smart_array& sa) {
		delete[] array;
		size = sa.size;
		last = sa.last;
		array = new int[size];
		for (unsigned i = 0; i < size; i++) {
			array[i] = sa.array[i];
		}
		return *this;
	}
	void add_element(int v) {
		if (last == size) throw std::runtime_error("smart_array is full!");
		array[last++] = v;
	}
	int get_element(unsigned i) {
		if (i >= size) throw std::runtime_error("index out of range!");
		return array[i];
	}
	void display() {
		for (unsigned i = 0; i < size; i++) {
			std::cout << array[i] << ' ';
		}
		std::cout << std::endl;
	}
	~smart_array() {		
		delete[] array;
	}
};

void test_copy() {
	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);
	arr.display();
	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);
	new_array.display();
	smart_array copy_array = arr;
	arr = new_array;
	copy_array.display();
	arr.display();
}

int main() {
	test_copy();
}