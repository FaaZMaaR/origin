#include <iostream>
#include <string>

struct Address {
	std::string city;
	std::string street;
	int houseNumber;
	int flatNumber;
	int index;
};

void displayAddress(const Address& address) {
	std::cout << "Город: " << address.city << std::endl;
	std::cout << "Улица: " << address.street << std::endl;
	std::cout << "Номер дома: " << address.houseNumber << std::endl;
	std::cout << "Номер кваритры: " << address.flatNumber << std::endl;
	std::cout << "Индекс: " << address.index << std::endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	Address address1{ "Москва","Арбат",12,8,123456 };
	Address address2{ "Самара","Ленина",44,5,579135 };
	displayAddress(address1);
	std::cout << std::endl;
	displayAddress(address2);
}