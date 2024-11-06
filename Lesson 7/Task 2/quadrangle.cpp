#include "quadrangle.h"

Quadrangle::Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D, std::string n, int s) : 
	Figure(n, s), a{ a }, b{ b }, c{ c }, d{ d }, A{ A }, B{ B }, C{ C }, D{ D } {}

Quadrangle::Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, c, d, A, B, C, D, "Четырехугольник", 4) {
	print_creation_info();
}

void Quadrangle::check() const {
	if (get_sides_count() != 4) throw bad_figure("количество сторон не равно 4");
	if (A + B + C + D != 360) throw bad_figure("сумма углов не равна 360");
}

void Quadrangle::print_sides_and_angles() const {
	std::cout << "стороны: " << a << ", " << b << ", " << c << ", " << d << "; углы: " << A << ", " << B << ", " << C << ", " << D;
}