#include <iostream>
#include <string>

#include "figure.h"
#include "triangle.h"
#include "right_triangle.h"
#include "isosceles_triangle.h"
#include "equilateral_triangle.h"
#include "quadrangle.h"
#include "parallelogram.h"
#include "rectangle.h"
#include "rhomb.h"
#include "square.h"

int main() {
	setlocale(LC_ALL, "rus");
	Triangle triangle{ 10,20,30,50,60,70 };
	RightTriangle rightTriangle{ 10,20,30,50,60 };
	IsoscelesTriangle isoscelesTriangle{ 10,20,50,60 };
	EquilateralTriangle equilateralTriangle{ 30 };
	Quadrangle quadrangle{ 10,20,30,40,50,60,70,80 };
	Rectangle rectangle{ 10,20 };
	Square square{ 20 };
	Parallelogram parallelogram{ 20,30,30,40 };
	Rhomb rhomb{ 30,30,40 };
}