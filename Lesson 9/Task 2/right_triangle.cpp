#include "right_triangle.h"

RightTriangle::RightTriangle(double a, double b, double c, double A, double B, std::string n) : Triangle(a, b, c, A, B, 90, n) {}

RightTriangle::RightTriangle(double a, double b, double c, double A, double B) : RightTriangle(a, b, c, A, B, "Прямоугольный треугольник") {}