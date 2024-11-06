#include <iostream>

#include "figure.h"

Figure::Figure(std::string n, int s) : name{ n }, sides_count{ s } {}

std::string Figure::get_name() const {
	return name;
}

int Figure::get_sides_count() const {
	return sides_count;
}

void Figure::print_creation_info() const {
	try {
		check();
		std::cout << get_name() << '(';
		print_sides_and_angles();
		std::cout << ") создан" << std::endl;
	}
	catch (bad_figure e) {
		std::cout << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
	}
}