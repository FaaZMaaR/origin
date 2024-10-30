#pragma once

#include "figure.h"

class Quadrangle : public Figure {
	protected:
		double a, b, c, d, A, B, C, D;
		Quadrangle(double, double, double, double, double, double, double, double, std::string);
	public:
		Quadrangle(double, double, double, double, double, double, double, double);
		void print_sides() const override;
		void print_angles() const override;
};