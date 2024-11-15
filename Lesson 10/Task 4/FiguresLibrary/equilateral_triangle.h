#pragma once

#include "isosceles_triangle.h"

#ifdef FIGURESLIBRARY_EXPORTS
#define FIGURESLIBRARY_API __declspec(dllexport)
#else
#define FIGURESLIBRARY_API __declspec(dllimport)
#endif

namespace Figures {
	class EquilateralTriangle : public IsoscelesTriangle {
		protected:
			EquilateralTriangle(double, std::string);
		public:
			FIGURESLIBRARY_API EquilateralTriangle(double);
	};
}