#pragma once

#include "rhomb.h"

class Square : public Rhomb {
	protected:
		Square(double, std::string);
	public:
		Square(double);
};