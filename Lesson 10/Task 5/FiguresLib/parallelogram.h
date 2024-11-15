#pragma once

#include <quadrangle.h>

namespace Figures {
	class Parallelogram : public Quadrangle {
		protected:
			Parallelogram(double, double, double, double, std::string);
		public:
			Parallelogram(double, double, double, double);
	};
}