#pragma once

#include "triangle.h"

#ifdef FIGURESLIBRARY_EXPORTS
#define FIGURESLIBRARY_API __declspec(dllexport)
#else
#define FIGURESLIBRARY_API __declspec(dllimport)
#endif

namespace Figures {
	class IsoscelesTriangle : public Triangle {
		protected:
			IsoscelesTriangle(double, double, double, double, std::string);
		public:
			FIGURESLIBRARY_API IsoscelesTriangle(double, double, double, double);
	};
}