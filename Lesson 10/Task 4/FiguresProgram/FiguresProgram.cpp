#include <iostream>
#include <string>
#include <Windows.h>

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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Figures::Triangle triangle{ 10,20,30,50,60,70 };
	Figures::RightTriangle rightTriangle{ 10,20,30,50,60 };
	Figures::IsoscelesTriangle isoscelesTriangle{ 10,20,50,60 };
	Figures::EquilateralTriangle equilateralTriangle{ 30 };
	Figures::Quadrangle quadrangle{ 10,20,30,40,50,60,70,80 };
	Figures::Rectangle rectangle{ 10,20 };
	Figures::Square square{ 20 };
	Figures::Parallelogram parallelogram{ 20,30,30,40 };
	Figures::Rhomb rhomb{ 30,30,40 };
	Figures::print_info(&triangle);
	Figures::print_info(&rightTriangle);
	Figures::print_info(&isoscelesTriangle);
	Figures::print_info(&equilateralTriangle);
	Figures::print_info(&quadrangle);
	Figures::print_info(&rectangle);
	Figures::print_info(&square);
	Figures::print_info(&parallelogram);
	Figures::print_info(&rhomb);
}