#include <iostream>
#include <string>

class Figure {
private:
	std::string name;
	int sides_count;
protected:
	Figure(std::string n, int s) : name{ n }, sides_count{ s } {}
	int get_sides_count() const {
		return sides_count;
	}
	virtual bool check() const {
		if (sides_count == 0) return true;
		else return false;
	}
	virtual void print_sides() const {}
	virtual void print_angles() const {}
public:
	Figure() : Figure("Фигура", 0) {}	
	void print_info() const {
		std::cout << name << ":" << std::endl;
		if (check()) {
			std::cout << "Правильная" << std::endl;
		}
		else {
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << sides_count << std::endl;
		print_sides();
		print_angles();
	}
};

class Triangle : public Figure {
protected:
	double a, b, c, A, B, C;
	Triangle(double a, double b, double c, double A, double B, double C, std::string n) : Figure(n, 3), a{ a }, b{ b }, c{ c }, A{ A }, B{ B }, C{ C } {}
	bool check() const override {
		if (get_sides_count() == 3 && A+B+C==180) return true;
		else return false;
	}
	void print_sides() const override {
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
	}
	void print_angles() const override {
		std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
	}
public:
	Triangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C, "Треугольник") {}
};

class RightTriangle : public Triangle {
protected:
	RightTriangle(double a, double b, double c, double A, double B, std::string n) : Triangle(a, b, c, A, B, 90, n) {}
	bool check() const override {
		if (Triangle::check() && C==90) return true;
		else return false;
	}
public:
	RightTriangle(double a, double b, double c, double A, double B) : RightTriangle(a, b, c, A, B, "Прямоугольный треугольник") {}
};

class IsoscelesTriangle : public Triangle {
protected:
	IsoscelesTriangle(double a, double b, double A, double B, std::string n) : Triangle(a, b, a, A, B, A, n) {}
	bool check() const override {
		if (Triangle::check() && a == c && A == C) return true;
		else return false;
	}
public:
	IsoscelesTriangle(double a, double b, double A, double B) : IsoscelesTriangle(a, b, A, B, "Равнобедренный треугольник") {}
};

class EquilateralTriangle : public IsoscelesTriangle {
protected:
	EquilateralTriangle(double a, std::string n) : IsoscelesTriangle(a, a, 60, 60, n) {}
	bool check() const override {
		if (IsoscelesTriangle::check() && a == b && A == B && A == 60) return true;
		else return false;
	}
public:
	EquilateralTriangle(double a) : EquilateralTriangle(a, "Равносторонний треугольник") {}
};

class Quadrangle : public Figure {
protected:
	double a, b, c, d, A, B, C, D;
	Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D, std::string n) : Figure(n, 4), a{ a }, b{ b }, c{ c }, d{ d }, A{ A }, B{ B }, C{ C }, D{ D } {}
	bool check() const override {
		if (get_sides_count() == 4 && A + B + C + D == 360) return true;
		else return false;
	}
	void print_sides() const override {
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
	}
	void print_angles() const override {
		std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
	}
public:
	Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, c, d, A, B, C, D, "Четырехугольник") {}	
};

class Parallelogram : public Quadrangle {
protected:
	Parallelogram(double a, double b, double A, double B, std::string n) : Quadrangle(a, b, a, b, A, B, A, B, n) {}
	bool check() const override {
		if (Quadrangle::check() && a == c && b == d && A == C && B == D) return true;
		else return false;
	}
public:
	Parallelogram(double a, double b, double A, double B) : Parallelogram(a, b, A, B, "Параллелограмм") {}
};

class Rectangle : public Parallelogram {
protected:
	Rectangle(double a, double b, std::string n) : Parallelogram(a, b, 90, 90, n) {}
	bool check() const override {
		if (Parallelogram::check() && A == B && A == 90) return true;
		else return false;
	}
public:
	Rectangle(double a, double b) : Rectangle(a, b, "Прямоугольник") {}
};

class Rhomb : public Parallelogram {
protected:
	Rhomb(double a, double A, double B, std::string n) : Parallelogram(a, a, A, B, n) {}
	bool check() const override {
		if (Parallelogram::check() && a == b) return true;
		else return false;
	}
public:
	Rhomb(double a, double A, double B) : Rhomb(a, A, B, "Ромб") {}
};

class Square : public Rhomb {
protected:
	Square(double a, std::string n) : Rhomb(a, 90, 90, n) {}
	bool check() const override {
		if (Rhomb::check() && A == B && A == 90) return true;
		else return false;
	}
public:
	Square(double a) : Square(a, "Квадрат") {}
};

int main() {
	setlocale(LC_ALL, "rus");
	Figure figure{};
	Triangle triangle{ 10,20,30,50,60,70 };
	RightTriangle rightTriangle{ 10,20,30,50,60 };
	RightTriangle rightTriangle2{ 10,20,30,50,40 };
	IsoscelesTriangle isoscelesTriangle{ 10,20,50,60 };
	EquilateralTriangle equilateralTriangle{ 30 };
	Quadrangle quadrangle{ 10,20,30,40,50,60,70,80 };
	Rectangle rectangle{ 10,20 };
	Square square{ 20 };
	Parallelogram parallelogram{ 20,30,30,40 };
	Rhomb rhomb{ 30,30,40 };
	Figure* figures[]{
		&figure,
		&triangle,
		&rightTriangle,
		&rightTriangle2,
		&isoscelesTriangle,
		&equilateralTriangle,
		&quadrangle,
		&rectangle,
		&square,
		&parallelogram,
		&rhomb
	};
	for (auto f : figures) {
		f->print_info();
		std::cout << std::endl;
	}
}