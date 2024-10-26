#include <iostream>
#include <string>

class Figure {
	private:
		int sides_count;
		std::string name;
	protected:		
		Figure(int s, std::string n) : sides_count{ s }, name{ n } {}
	public:
		Figure() : Figure(0,"Фигура") {}
		int get_sides_count() const {
			return sides_count;
		}
		std::string get_name() const {
			return name;
		}
};

class Triangle : public Figure {
	public:
		Triangle() : Figure(3,"Треугольник") {}
};

class Quadrangle : public Figure {
	public:
		Quadrangle() : Figure(4, "Четырехугольник") {}
};

void print_figure(Figure* f) {
	std::cout << f->get_name() << ": " << f->get_sides_count() << std::endl;
}

int main() {
	setlocale(LC_ALL,"rus");
	Figure figure;
	Triangle triangle;
	Quadrangle quadrangle;
	std::cout << "Количество сторон:" << std::endl;
	print_figure(&figure);
	print_figure(&triangle);
	print_figure(&quadrangle);
}