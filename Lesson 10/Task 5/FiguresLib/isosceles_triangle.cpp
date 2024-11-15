#include "isosceles_triangle.h"

namespace Figures {
	IsoscelesTriangle::IsoscelesTriangle(double a, double b, double A, double B, std::string n) : Triangle(a, b, a, A, B, A, n) {}

	IsoscelesTriangle::IsoscelesTriangle(double a, double b, double A, double B) : IsoscelesTriangle(a, b, A, B, "Равнобедренный треугольник") {}
}
