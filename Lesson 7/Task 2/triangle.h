#pragma once

#include "figure.h"

class Triangle : public Figure {
	protected:
		double a, b, c, A, B, C;
		Triangle(double, double, double, double, double, double, std::string, int);
		void check() const override;
	public:
		Triangle(double, double, double, double, double, double);
		void print_sides_and_angles() const override;
};