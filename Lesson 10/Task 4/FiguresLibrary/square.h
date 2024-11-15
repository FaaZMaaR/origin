#pragma once

#include "rhomb.h"

#ifdef FIGURESLIBRARY_EXPORTS
#define FIGURESLIBRARY_API __declspec(dllexport)
#else
#define FIGURESLIBRARY_API __declspec(dllimport)
#endif

namespace Figures {
	class Square : public Rhomb {
		protected:
			Square(double, std::string);
		public:
			FIGURESLIBRARY_API Square(double);
	};
}
