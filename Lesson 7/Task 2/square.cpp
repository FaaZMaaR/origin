#include "square.h"

Square::Square(double a, std::string n) : Rhomb(a, 90, 90, n) {}

Square::Square(double a) : Square(a, "Квадрат") {
	print_creation_info();
}

void Square::check() const {
	Rhomb::check();
	if (A != B) throw bad_figure("не все углы равны 90");
}