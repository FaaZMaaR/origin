#pragma once

#include <triangle.h>

namespace Figures {
	class IsoscelesTriangle : public Triangle {
		protected:
			IsoscelesTriangle(double, double, double, double, std::string);
		public:
			IsoscelesTriangle(double, double, double, double);
	};
}