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
	std::cout << "�����: " << address.city << std::endl;
	std::cout << "�����: " << address.street << std::endl;
	std::cout << "����� ����: " << address.houseNumber << std::endl;
	std::cout << "����� ��������: " << address.flatNumber << std::endl;
	std::cout << "������: " << address.index << std::endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	Address address1{ "������","�����",12,8,123456 };
	Address address2{ "������","������",44,5,579135 };
	displayAddress(address1);
	std::cout << std::endl;
	displayAddress(address2);
}