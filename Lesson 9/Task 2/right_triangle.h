#pragma once

#include "triangle.h"

class RightTriangle : public Triangle {
	protected:
		RightTriangle(double, double, double, double, double, std::string);
	public:
		RightTriangle(double, double, double, double, double);
};