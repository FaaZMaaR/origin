#pragma once

#include <string>

namespace Figures {
	class Figure {
		private:
			std::string name;
		protected:
			Figure(std::string);
		public:
			std::string get_name() const;
			virtual void print_sides() const = 0;
			virtual void print_angles() const = 0;
		};

	void print_info(Figure*);
}