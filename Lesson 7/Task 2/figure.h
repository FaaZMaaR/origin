#pragma once

#include <string>

#include "bad_figure.h"

class Figure {
	private:
		std::string name;
		int sides_count;
	protected:
		Figure(std::string,int);
		virtual void check() const = 0;
		void print_creation_info() const;
	public:
		std::string get_name() const;
		int get_sides_count() const;
		virtual void print_sides_and_angles() const = 0;		
};