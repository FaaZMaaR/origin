#include <iostream>
#include <Windows.h>

#include "greeter.h"

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string name;
	std::cout << "Введите имя: ";
	std::cin >> name;
	Greeter greeter;
	std::cout << greeter.greet(name) << std::endl;
}