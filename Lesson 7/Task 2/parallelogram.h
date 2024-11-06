#pragma once

#include "quadrangle.h"

class Parallelogram : public Quadrangle {
	protected:
		Parallelogram(double, double, double, double, std::string);
		void check() const override;
	public:
		Parallelogram(double, double, double, double);
};