#include "parallelogram.h"

Parallelogram::Parallelogram(double a, double b, double A, double B, std::string n) : Quadrangle(a, b, a, b, A, B, A, B, n, 4) {}

Parallelogram::Parallelogram(double a, double b, double A, double B) : Parallelogram(a, b, A, B, "Параллелограмм") {
	print_creation_info();
}

void Parallelogram::check() const {
	Quadrangle::check();
	if (a != c) throw bad_figure("стороны a и c не равны");
	if (b != d) throw bad_figure("стороны b и d не равны");
	if (A != C) throw bad_figure("углы A и C не равны");
	if (B != D) throw bad_figure("углы B и D не равны");
}