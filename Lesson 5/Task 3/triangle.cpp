#include <iostream>

#include "triangle.h"

Triangle::Triangle(double a, double b, double c, double A, double B, double C, std::string n) : Figure(n), a{ a }, b{ b }, c{ c }, A{ A }, B{ B }, C{ C } {}

Triangle::Triangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C, "Треугольник") {}

void Triangle::print_sides() const {
	std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
}

void Triangle::print_angles() const {
	std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
}