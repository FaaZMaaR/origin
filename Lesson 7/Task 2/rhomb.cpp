#include "rhomb.h"

Rhomb::Rhomb(double a, double A, double B, std::string n) : Parallelogram(a, a, A, B, n) {}

Rhomb::Rhomb(double a, double A, double B) : Rhomb(a, A, B, "Ромб") {
	print_creation_info();
}

void Rhomb::check() const {
	Parallelogram::check();
	if (a != b) throw("стороны не равны");
}