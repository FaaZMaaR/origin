#pragma once

#include "figure.h"

class Triangle : public Figure {
	protected:
		double a, b, c, A, B, C;
		Triangle(double, double, double, double, double, double, std::string);
	public:
		Triangle(double, double, double, double, double, double);
		void print_sides() const override;
		void print_angles() const override;
};