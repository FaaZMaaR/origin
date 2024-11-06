#include <iostream>
#include <string>
#include <Windows.h>

struct bad_length : public std::exception {};

int function(const std::string& str, int forbidden_length) {
	if (str.size() == forbidden_length) {
		throw bad_length();
	}
	else {
		return str.size();
	}
}

void ask_user(int forbidden_length) {
	std::string answer;
	std::cout << "Введите слово: ";
	std::cin >> answer;
	int answer_size = function(answer, forbidden_length);
	std::cout << "Длина слова \"" << answer << "\" равна " << answer_size << std::endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int forbidden_length;
	std::cout << "Введите запретную длину: ";
	std::cin >> forbidden_length;
	try {
		while (true) {
			ask_user(forbidden_length);
		}
	}
	catch (const bad_length& e) {
		std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
	}
}