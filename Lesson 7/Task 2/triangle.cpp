#include "triangle.h"

Triangle::Triangle(double a, double b, double c, double A, double B, double C, std::string n,int s) : Figure(n,s), a{ a }, b{ b }, c{ c }, A{ A }, B{ B }, C{ C } {}

Triangle::Triangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C, "Треугольник", 3) {
	print_creation_info();
}

void Triangle::check() const{
	if (get_sides_count() != 3) throw bad_figure("количество сторон не равно 3");
	if (A + B + C != 180) throw bad_figure("сумма углов не равна 180");
}

void Triangle::print_sides_and_angles() const {
	std::cout << "стороны: " << a << ", " << b << ", " << c << "; углы: " << A << ", " << B << ", " << C;
}