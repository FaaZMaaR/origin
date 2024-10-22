#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
	std::string city;
	std::string street;
	int house;
	int flat;
public:
	Address() : Address("", "", 0, 0) {}
	Address(const std::string& c, const std::string& s, int h, int f) : city(c), street(s), house(h), flat(f) {}
	void read(std::istream& is) {
		is >> city >> street >> house >> flat;
	}
	void write(std::ostream& os) const {
		os << city << ", " << street << ", " << house << ", " << flat << std::endl;
	}
	std::string getCity() const {
		return city;
	}
};

void readAdresses(const char* path, Address*& arr, int& size) {
	std::ifstream file(path);
	if (!file.is_open()) {
		std::cout << "Не удалось открыть файл" << std::endl;
		exit(1);
	}
	file >> size;
	if (arr != nullptr) delete[] arr;
	arr = new Address[size];
	for (int i = 0; i < size; i++) {
		arr[i].read(file);
	}
	file.close();
}

void writeAddresses(const char* path, Address* arr, int size) {
	std::ofstream file(path);
	if (!file.is_open()) {
		std::cout << "Не удалось открыть файл" << std::endl;
		exit(1);
	}
	file << size << std::endl;
	for (int i = 0; i < size; i++) {
		arr[i].write(file);
	}
	file.close();
}

void swapAddresses(Address& a, Address& b) {
	Address tmp = a;
	a = b;
	b = tmp;
}

void sortAddresses(Address*& arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i; j < size - 1 - i; j++) {
			if (arr[j].getCity() > arr[j + 1].getCity()) {
				swapAddresses(arr[j], arr[j + 1]);
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	Address* addresses{};
	int size = 0;
	readAdresses("in.txt", addresses, size);
	sortAddresses(addresses, size);
	writeAddresses("out.txt", addresses, size);
	delete[] addresses;
}