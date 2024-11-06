#include "equilateral_triangle.h"

EquilateralTriangle::EquilateralTriangle(double a, std::string n) : IsoscelesTriangle(a, a, 60, 60, n) {}

EquilateralTriangle::EquilateralTriangle(double a) : EquilateralTriangle(a, "Равносторонний треугольник") {
	print_creation_info();
}

void EquilateralTriangle::check() const {
	IsoscelesTriangle::check();
	if (a != b) throw bad_figure("стороны не равны");
	if (A != B) throw bad_figure("не все углы равны 60");
}