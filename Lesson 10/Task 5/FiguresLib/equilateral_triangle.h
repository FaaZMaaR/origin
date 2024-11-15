#pragma once

#include <isosceles_triangle.h>

namespace Figures {
	class EquilateralTriangle : public IsoscelesTriangle {
		protected:
			EquilateralTriangle(double, std::string);
		public:
			EquilateralTriangle(double);
	};
}