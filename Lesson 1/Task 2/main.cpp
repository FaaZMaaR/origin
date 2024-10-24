#include <iostream>
#include <string>
#include <Windows.h>

struct Account {
	int number;
	std::string name;
	double balance;
};

void inputAccount(Account& account) {
	std::cout << "������� ����� �����: ";
	std::cin >> account.number;
	std::cout << "������� ��� ���������: ";
	std::cin >> account.name;
	std::cout << "������� ������: ";
	std::cin >> account.balance;
}

void setBalance(Account& account, double newBalance) {
	account.balance = newBalance;
}

void displayAccount(const Account& account) {
	std::cout << account.name << ", " << account.number << ", " << account.balance;
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Account account{ 0,"",0 };
	inputAccount(account);
	double newBalance = 0;
	std::cout << "������� ����� ������: ";
	std::cin >> newBalance;
	setBalance(account, newBalance);
	std::cout << "��� ����: ";
	displayAccount(account);
}