#include "functions.h"

double add(double a, double b) {
	return a + b;
}

double sub(double a, double b) {
	return a - b;
}

double mul(double a, double b) {
	return a * b;
}

double div(double a, double b) {
	return a / b;
}

double power(double a, int n) {
	double res = 1;
	for (int i = 0; i < n; i++) {
		res *= a;
	}
	return res;
}