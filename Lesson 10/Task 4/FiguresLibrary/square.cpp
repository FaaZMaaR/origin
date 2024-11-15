#include "square.h"

namespace Figures {
	Square::Square(double a, std::string n) : Rhomb(a, 90, 90, n) {}

	Square::Square(double a) : Square(a, "Квадрат") {}
}