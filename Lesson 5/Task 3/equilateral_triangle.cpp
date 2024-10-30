#include "equilateral_triangle.h"

EquilateralTriangle::EquilateralTriangle(double a, std::string n) : IsoscelesTriangle(a, a, 60, 60, n) {}

EquilateralTriangle::EquilateralTriangle(double a) : EquilateralTriangle(a, "Равносторонний треугольник") {}