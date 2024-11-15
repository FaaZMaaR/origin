#include <iostream>
#include <Windows.h>

#include "leaver.h"

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string name;
	std::cout << "Введите имя: ";
	std::cin >> name;
	Leaver leaver;
	std::cout << leaver.leave(name) << std::endl;
}