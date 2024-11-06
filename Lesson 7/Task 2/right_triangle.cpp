#include "right_triangle.h"

RightTriangle::RightTriangle(double a, double b, double c, double A, double B, std::string n) : Triangle(a, b, c, A, B, 90, n, 3) {}

RightTriangle::RightTriangle(double a, double b, double c, double A, double B) : RightTriangle(a, b, c, A, B, "Прямоугольный треугольник") {
	print_creation_info();
}

void RightTriangle::check() const {
	Triangle::check();
	if (C != 90) throw bad_figure("угол C не равен 90");
}