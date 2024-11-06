#pragma once

#include "parallelogram.h"

class Rectangle : public Parallelogram {
	protected:
		Rectangle(double, double, std::string);
		void check() const override;
	public:
		Rectangle(double, double);
};