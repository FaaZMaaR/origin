#include <iostream>

enum class Months {
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

void printMonth(Months month) {
	switch (month) {
		case Months::JANUARY:
			std::cout << "������" << std::endl;
			break;
		case Months::FEBRUARY:
			std::cout << "�������" << std::endl;
			break;
		case Months::MARCH:
			std::cout << "����" << std::endl;
			break;
		case Months::APRIL:
			std::cout << "������" << std::endl;
			break;
		case Months::MAY:
			std::cout << "���" << std::endl;
			break;
		case Months::JUNE:
			std::cout << "����" << std::endl;
			break;
		case Months::JULY:
			std::cout << "����" << std::endl;
			break;
		case Months::AUGUST:
			std::cout << "������" << std::endl;
			break;
		case Months::SEPTEMBER:
			std::cout << "��������" << std::endl;
			break;
		case Months::OCTOBER:
			std::cout << "�������" << std::endl;
			break;
		case Months::NOVEMBER:
			std::cout << "������" << std::endl;
			break;
		case Months::DECEMBER:
			std::cout << "�������" << std::endl;
			break;
		default:
			std::cout << "������������ �����!" << std::endl;

	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int number = 0;
	while (true) {
		std::cout << "������� ����� ������: ";
		std::cin >> number;
		if (number == 0) {
			std::cout << "�� ��������" << std::endl;
			break;
		}
		else {
			printMonth(static_cast<Months>(number));
		}
	}
}