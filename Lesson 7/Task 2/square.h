#pragma once

#include "rhomb.h"

class Square : public Rhomb {
	protected:
		Square(double, std::string);
		void check() const override;
	public:
		Square(double);
};