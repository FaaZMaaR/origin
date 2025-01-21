#include <iostream>

template<typename T>
class table {
private:
	T** two_dim_array;
	unsigned rows, columns;

public:
	table(unsigned rows, unsigned columns) : two_dim_array{ new T * [rows] }, rows{ rows }, columns{ columns } {
		for (unsigned i = 0; i < rows; i++) {
			two_dim_array[i] = new T[columns]{};
		}
	}
	~table() {
		for (unsigned i = 0; i < rows; i++) {
			delete[] two_dim_array[i];
		}
		delete[] two_dim_array;
	}
	const T*& operator[](unsigned index) const {
		return two_dim_array[index];
	}
	T*& operator[](unsigned index) {
		return two_dim_array[index];
	}
	unsigned Size() const {
		return rows * columns;
	}

};

int main() {
	auto test = table<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0];
	std::cout << "\ntest.Size() = " << test.Size();
}