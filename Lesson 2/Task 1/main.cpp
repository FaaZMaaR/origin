#include <iostream>

class Calculator {
private:
	double num1, num2;
	double add() {
		return num1 + num2;
	}
	double multiply() {
		return num1 * num2;
	}
	double subtract_1_2() {
		return num1 - num2;
	}
	double subtract_2_1() {
		return num2 - num1;
	}
	double divide_1_2() {
		return num1 / num2;
	}
	double divide_2_1() {
		return num2 / num1;
	}
	bool set_num1(double num1) {
		if (num1 != 0) {
			this->num1 = num1;
			return true;
		}
		else {
			return false;
		}
	}
	bool set_num2(double num2) {
		if (num2 != 0) {
			this->num2 = num2;
			return true;
		}
		else {
			return false;
		}
	}
public:		
	void display_results() {
		std::cout << "num1 + num2 = " << add() << std::endl;
		std::cout << "num1 - num2 = " << subtract_1_2() << std::endl;
		std::cout << "num2 - num1 = " << subtract_2_1() << std::endl;
		std::cout << "num1 * num2 = " << multiply() << std::endl;
		std::cout << "num1 / num2 = " << divide_1_2() << std::endl;
		std::cout << "num2 / num1 = " << divide_2_1() << std::endl;
	}
	void input_nums() {
		while (true) {
			double n = 0;
			std::cout << "Введите num1: ";
			std::cin >> n;
			if (!set_num1(n)) {
				std::cout << "Неверный ввод!" << std::endl;
				continue;
			}
			else {
				break;
			}
		}
		while (true) {
			double n = 0;
			std::cout << "Введите num2: ";
			std::cin >> n;
			if (!set_num2(n)) {
				std::cout << "Неверный ввод!" << std::endl;
				continue;
			}
			else {
				break;
			}
		}
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	Calculator calculator;
	while (true) {
		calculator.input_nums();
		calculator.display_results();
	}
}