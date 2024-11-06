#include "rectangle.h"

Rectangle::Rectangle(double a, double b, std::string n) : Parallelogram(a, b, 90, 90, n) {}

Rectangle::Rectangle(double a, double b) : Rectangle(a, b, "Прямоугольник") {
	print_creation_info();
}

void Rectangle::check() const {
	Parallelogram::check();
	if (A != B) throw("не все углы равны 90");
}