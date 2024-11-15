#pragma once

#include "parallelogram.h"

#ifdef FIGURESLIBRARY_EXPORTS
#define FIGURESLIBRARY_API __declspec(dllexport)
#else
#define FIGURESLIBRARY_API __declspec(dllimport)
#endif

namespace Figures {
	class Rectangle : public Parallelogram {
		protected:
			Rectangle(double, double, std::string);
		public:
			FIGURESLIBRARY_API Rectangle(double, double);
	};
}
