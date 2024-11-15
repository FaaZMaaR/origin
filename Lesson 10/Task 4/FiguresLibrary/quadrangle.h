#pragma once

#include "figure.h"

#ifdef FIGURESLIBRARY_EXPORTS
#define FIGURESLIBRARY_API __declspec(dllexport)
#else
#define FIGURESLIBRARY_API __declspec(dllimport)
#endif

namespace Figures {
	class Quadrangle : public Figure {
		protected:
			double a, b, c, d, A, B, C, D;
			Quadrangle(double, double, double, double, double, double, double, double, std::string);
		public:
			FIGURESLIBRARY_API Quadrangle(double, double, double, double, double, double, double, double);
			FIGURESLIBRARY_API void print_sides() const override;
			FIGURESLIBRARY_API void print_angles() const override;
	};
}