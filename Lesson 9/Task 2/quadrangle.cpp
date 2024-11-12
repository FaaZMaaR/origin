#include <iostream>

#include "quadrangle.h"

Quadrangle::Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D, std::string n) : Figure(n), a{ a }, b{ b }, c{ c }, d{ d }, A{ A }, B{ B }, C{ C }, D{ D } {}

Quadrangle::Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, c, d, A, B, C, D, "Четырехугольник") {}

void Quadrangle::print_sides() const {
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
}

void Quadrangle::print_angles() const {
	std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
}