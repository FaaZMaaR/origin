cmake_minimum_required(VERSION 3.22.0)

project(figures_project)

add_executable(
	run_figures

	main.cpp
	figure.h figure.cpp
	triangle.h triangle.cpp
	right_triangle.h right_triangle.cpp
	isosceles_triangle.h isosceles_triangle.cpp
	equilateral_triangle.h equilateral_triangle.cpp
	quadrangle.h quadrangle.cpp
	parallelogram.h parallelogram.cpp
	rectangle.h rectangle.cpp
	rhomb.h rhomb.cpp
	square.h square.cpp
)