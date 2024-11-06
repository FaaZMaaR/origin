#include "isosceles_triangle.h"

IsoscelesTriangle::IsoscelesTriangle(double a, double b, double A, double B, std::string n) : Triangle(a, b, a, A, B, A, n, 3) {}

IsoscelesTriangle::IsoscelesTriangle(double a, double b, double A, double B) : IsoscelesTriangle(a, b, A, B, "Равнобедренный треугольник") {
	print_creation_info();
}

void IsoscelesTriangle::check() const {
	Triangle::check();
	if (a != c) throw bad_figure("стороны a и c не равны");
	if (A != C) throw bad_figure("углы A и C не равны");
}