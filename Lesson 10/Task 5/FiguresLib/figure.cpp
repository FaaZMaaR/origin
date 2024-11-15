#include <iostream>

#include "figure.h"

namespace Figures {
	Figure::Figure(std::string n) : name{ n } {}

	std::string Figure::get_name() const {
		return name;
	}

	void print_info(Figure* f) {
		std::cout << f->get_name() << ":" << std::endl;
		f->print_sides();
		f->print_angles();
		std::cout << std::endl;
	}
}