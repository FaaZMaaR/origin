#pragma once

#include <string>

#ifdef FIGURESLIBRARY_EXPORTS
#define FIGURESLIBRARY_API __declspec(dllexport)
#else
#define FIGURESLIBRARY_API __declspec(dllimport)
#endif

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

	FIGURESLIBRARY_API void print_info(Figure*);
}