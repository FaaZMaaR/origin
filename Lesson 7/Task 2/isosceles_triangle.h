#pragma once

#include "triangle.h"

class IsoscelesTriangle : public Triangle {
	protected:
		IsoscelesTriangle(double, double, double, double, std::string);
		void check() const override;
	public:
		IsoscelesTriangle(double, double, double, double);
};