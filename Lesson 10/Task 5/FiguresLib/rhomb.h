#pragma once

#include <parallelogram.h>

namespace Figures {
	class Rhomb : public Parallelogram {
		protected:
			Rhomb(double, double, double, std::string);
		public:
			Rhomb(double, double, double);
	};
}