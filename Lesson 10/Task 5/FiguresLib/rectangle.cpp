#include "rectangle.h"

namespace Figures {
	Rectangle::Rectangle(double a, double b, std::string n) : Parallelogram(a, b, 90, 90, n) {}

	Rectangle::Rectangle(double a, double b) : Rectangle(a, b, "Прямоугольник") {}
}
