#include <iostream>

#include "functions.h"

int main() {
	setlocale(LC_ALL, "rus");
	double num1, num2;
	std::cout << "Введите первое число: ";
	std::cin >> num1;
	std::cout << "Введите второе число: ";
	std::cin >> num2;
	int var = 1;
	std::cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	std::cin >> var;
	switch (var) {
		case 1:
			std::cout << num1 << " + " << num2 << " = " << add(num1, num2) << std::endl;
			break;
		case 2:
			std::cout << num1 << " - " << num2 << " = " << sub(num1, num2) << std::endl;
			break;
		case 3:
			std::cout << num1 << " * " << num2 << " = " << mul(num1, num2) << std::endl;
			break;
		case 4:
			std::cout << num1 << " / " << num2 << " = " << div(num1, num2) << std::endl;
			break;
		case 5:
			std::cout << num1 << " в степени " << num2 << " = " << power(num1, num2) << std::endl;
			break;
		default:
			std::cout << "Неизвестная операция" << std::endl;
	}
}