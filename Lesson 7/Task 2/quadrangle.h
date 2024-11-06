#pragma once

#include "figure.h"

class Quadrangle : public Figure {
	protected:
		double a, b, c, d, A, B, C, D;
		Quadrangle(double, double, double, double, double, double, double, double, std::string, int);
		void check() const override;
	public:
		Quadrangle(double, double, double, double, double, double, double, double);
		void print_sides_and_angles() const override;
};