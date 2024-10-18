#include <iostream>
#include <string>
#include <Windows.h>

class Counter {
private:
	int number;
public:
	Counter() : number(1) {}
	Counter(int n) : number(n) {}
	void increase() {
		++number;
	}
	void decrease() {
		--number;
	}
	int get() {
		return number;
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string answer;
	std::cout << "Вы хотите указать начальное значение счетчика? Введите да или нет: ";
	std::cin >> answer;
	int n = 1;
	if (answer == "да") {
		std::cout << "Введите начальное значение счетчика: ";
		std::cin >> n;
	}
	Counter counter{ n };
	while (true) {
		char ch;
		std::cout << "Введите команду (\'+\', \'-\', \'=\' или \'x\'): ";
		std::cin >> ch;
		switch (ch) {
			case '+':
				counter.increase();
				break;
			case '-':
				counter.decrease();
				break;
			case '=':
				std::cout << counter.get() << std::endl;
				break;
			case 'x':
				std::cout << "До свидания" << std::endl;			
				return 0;
			default:
				std::cout << "Неизвестная команда!" << std::endl;
		}
	}
}