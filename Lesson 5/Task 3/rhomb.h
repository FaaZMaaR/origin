#pragma once

#include "parallelogram.h"

class Rhomb : public Parallelogram {
	protected:
		Rhomb(double, double, double, std::string);
	public:
		Rhomb(double, double, double);
};