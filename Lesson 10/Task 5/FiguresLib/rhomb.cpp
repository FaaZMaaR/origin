#include "rhomb.h"

namespace Figures {
	Rhomb::Rhomb(double a, double A, double B, std::string n) : Parallelogram(a, a, A, B, n) {}

	Rhomb::Rhomb(double a, double A, double B) : Rhomb(a, A, B, "Ромб") {}
}