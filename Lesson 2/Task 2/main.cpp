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
	std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
	std::cin >> answer;
	int n = 1;
	if (answer == "��") {
		std::cout << "������� ��������� �������� ��������: ";
		std::cin >> n;
	}
	Counter counter{ n };
	while (true) {
		char ch;
		std::cout << "������� ������� (\'+\', \'-\', \'=\' ��� \'x\'): ";
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
				std::cout << "�� ��������" << std::endl;			
				return 0;
			default:
				std::cout << "����������� �������!" << std::endl;
		}
	}
}