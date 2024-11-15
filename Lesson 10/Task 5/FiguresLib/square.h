#pragma once

#include <rhomb.h>

namespace Figures {
	class Square : public Rhomb {
		protected:
			Square(double, std::string);
		public:
			Square(double);
	};
}
