#pragma once

#include <parallelogram.h>

namespace Figures {
	class Rectangle : public Parallelogram {
		protected:
			Rectangle(double, double, std::string);
		public:
			Rectangle(double, double);
	};
}
