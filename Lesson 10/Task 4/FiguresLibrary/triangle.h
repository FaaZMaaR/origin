#pragma once

#include "figure.h"

#ifdef FIGURESLIBRARY_EXPORTS
#define FIGURESLIBRARY_API __declspec(dllexport)
#else
#define FIGURESLIBRARY_API __declspec(dllimport)
#endif

namespace Figures {
	class Triangle : public Figure {
		protected:
			double a, b, c, A, B, C;
			Triangle(double, double, double, double, double, double, std::string);
		public:
			FIGURESLIBRARY_API Triangle(double, double, double, double, double, double);
			FIGURESLIBRARY_API void print_sides() const override;
			FIGURESLIBRARY_API void print_angles() const override;
	};
}