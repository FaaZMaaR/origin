#pragma once

#include "parallelogram.h"

class Rectangle : public Parallelogram {
	protected:
		Rectangle(double, double, std::string);
	public:
		Rectangle(double, double);
};