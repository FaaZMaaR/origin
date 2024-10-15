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
			std::cout << "Январь" << std::endl;
			break;
		case Months::FEBRUARY:
			std::cout << "Февраль" << std::endl;
			break;
		case Months::MARCH:
			std::cout << "Март" << std::endl;
			break;
		case Months::APRIL:
			std::cout << "Апрель" << std::endl;
			break;
		case Months::MAY:
			std::cout << "Май" << std::endl;
			break;
		case Months::JUNE:
			std::cout << "Июнь" << std::endl;
			break;
		case Months::JULY:
			std::cout << "Июль" << std::endl;
			break;
		case Months::AUGUST:
			std::cout << "Август" << std::endl;
			break;
		case Months::SEPTEMBER:
			std::cout << "Сентябрь" << std::endl;
			break;
		case Months::OCTOBER:
			std::cout << "Октябрь" << std::endl;
			break;
		case Months::NOVEMBER:
			std::cout << "Ноябрь" << std::endl;
			break;
		case Months::DECEMBER:
			std::cout << "Декабрь" << std::endl;
			break;
		default:
			std::cout << "Неправильный номер!" << std::endl;

	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int number = 0;
	while (true) {
		std::cout << "Введите номер месяца: ";
		std::cin >> number;
		if (number == 0) {
			std::cout << "До свидания" << std::endl;
			break;
		}
		else {
			printMonth(static_cast<Months>(number));
		}
	}
}