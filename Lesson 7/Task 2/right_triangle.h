#pragma once

#include "triangle.h"

class RightTriangle : public Triangle {
	protected:
		RightTriangle(double, double, double, double, double, std::string);
		void check() const override;
	public:
		RightTriangle(double, double, double, double, double);
};