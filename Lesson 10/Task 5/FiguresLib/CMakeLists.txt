add_library(figures_library SHARED)

target_sources(figures_library
	PUBLIC
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

target_include_directories(figures_library
	PUBLIC
		"./"
)