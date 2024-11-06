#pragma once

#include "isosceles_triangle.h"

class EquilateralTriangle : public IsoscelesTriangle {
	protected:
		EquilateralTriangle(double, std::string);
		void check() const override;
	public:
		EquilateralTriangle(double);
};