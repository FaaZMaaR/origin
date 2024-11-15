#pragma once

#include "parallelogram.h"

#ifdef FIGURESLIBRARY_EXPORTS
#define FIGURESLIBRARY_API __declspec(dllexport)
#else
#define FIGURESLIBRARY_API __declspec(dllimport)
#endif

namespace Figures {
	class Rhomb : public Parallelogram {
		protected:
			Rhomb(double, double, double, std::string);
		public:
			FIGURESLIBRARY_API Rhomb(double, double, double);
	};
}