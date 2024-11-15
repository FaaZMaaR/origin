#include "parallelogram.h"

namespace Figures {
	Parallelogram::Parallelogram(double a, double b, double A, double B, std::string n) : Quadrangle(a, b, a, b, A, B, A, B, n) {}

	Parallelogram::Parallelogram(double a, double b, double A, double B) : Parallelogram(a, b, A, B, "Параллелограмм") {}
}