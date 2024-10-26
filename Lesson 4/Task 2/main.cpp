#include <iostream>
#include <string>

class Figure {
	private:
		std::string name;
	protected:		
		Figure(std::string n) : name{ n } {}
	public:
		std::string get_name() const {
			return name;
		}
		virtual void print_sides() const = 0;
		virtual void print_angles() const = 0;
};

class Triangle : public Figure {
	protected:
		double a, b, c, A, B, C;
		Triangle(double a, double b, double c, double A, double B, double C, std::string n) : Figure(n), a{ a }, b{ b }, c{ c }, A{ A }, B{ B }, C{ C } {}
	public:
		Triangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C, "Треугольник") {}
		void print_sides() const override {
			std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
		}
		void print_angles() const override {
			std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
		}
};

class RightTriangle : public Triangle {
	protected:
		RightTriangle(double a, double b, double c, double A, double B, std::string n) : Triangle(a, b, c, A, B, 90, n) {}
	public:
		RightTriangle(double a, double b, double c, double A, double B) : RightTriangle(a, b, c, A, B, "Прямоугольный треугольник") {}
};

class IsoscelesTriangle : public Triangle {
	protected:
		IsoscelesTriangle(double a, double b, double A, double B, std::string n) : Triangle(a, b, a, A, B, A, n) {}
	public:
		IsoscelesTriangle(double a, double b, double A, double B) : IsoscelesTriangle(a, b, A, B, "Равнобедренный треугольник") {}
};

class EquilateralTriangle : public IsoscelesTriangle {
	protected:
		EquilateralTriangle(double a, std::string n) : IsoscelesTriangle(a, a, 60, 60, n) {}
	public:
		EquilateralTriangle(double a) : EquilateralTriangle(a, "Равносторонний треугольник") {}
};

class Quadrangle : public Figure {
	protected:
		double a, b, c, d, A, B, C, D;
		Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D, std::string n) : Figure(n), a{ a }, b{ b }, c{ c }, d{ d }, A{ A }, B{ B }, C{ C }, D{ D } {}
	public:
		Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, c, d, A, B, C, D, "Четырехугольник") {}
		void print_sides() const override {
			std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		}
		void print_angles() const override {
			std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
		}
};

class Parallelogram : public Quadrangle {
	protected:
		Parallelogram(double a, double b, double A, double B, std::string n) : Quadrangle(a, b, a, b, A, B, A, B, n) {}
	public:
		Parallelogram(double a, double b, double A, double B) : Parallelogram(a, b, A, B, "Параллелограмм") {}
};

class Rectangle : public Parallelogram {
	protected:
		Rectangle(double a, double b, std::string n) : Parallelogram(a, b, 90, 90, n) {}
	public:
		Rectangle(double a, double b) : Rectangle(a, b, "Прямоугольник") {}
};

class Rhomb : public Parallelogram {
	protected:
		Rhomb(double a, double A, double B, std::string n) : Parallelogram(a, a, A, B, n) {}
	public:
		Rhomb(double a, double A, double B) : Rhomb(a, A, B, "Ромб") {}
};

class Square : public Rhomb {
	protected:
		Square(double a, std::string n) : Rhomb(a, 90, 90, n) {}
	public:
		Square(double a) : Square(a, "Квадрат") {}
};

void print_info(Figure* f) {
	std::cout << f->get_name() << ":" << std::endl;
	f->print_sides();
	f->print_angles();
	std::cout << std::endl;
}

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
	print_info(&triangle);
	print_info(&rightTriangle);
	print_info(&isoscelesTriangle);
	print_info(&equilateralTriangle);
	print_info(&quadrangle);
	print_info(&rectangle);
	print_info(&square);
	print_info(&parallelogram);
	print_info(&rhomb);
}