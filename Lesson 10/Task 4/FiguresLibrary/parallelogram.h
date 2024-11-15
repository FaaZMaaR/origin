#pragma once

#include "quadrangle.h"

#ifdef FIGURESLIBRARY_EXPORTS
#define FIGURESLIBRARY_API __declspec(dllexport)
#else
#define FIGURESLIBRARY_API __declspec(dllimport)
#endif

namespace Figures {
	class Parallelogram : public Quadrangle {
		protected:
			Parallelogram(double, double, double, double, std::string);
		public:
			FIGURESLIBRARY_API Parallelogram(double, double, double, double);
	};
}