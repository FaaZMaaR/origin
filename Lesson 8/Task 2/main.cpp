#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

	void shorten() {
		if (denominator_ == 0) {
			std::cout << "Ошибка! Нулевой знаменатель!" << std::endl;
			exit(1);
		}
		if (denominator_ < 0) {
			numerator_ = -numerator_;
			denominator_ = -denominator_;
		}		
		int min = (abs(numerator_) < denominator_) ? abs(numerator_) : denominator_;
		int div = 1;
		for (int i = min; i > 1; i--) {
			if (numerator_ % i == 0 && denominator_ % i == 0) {
				div = i;
				break;
			}
		}
		numerator_ /= div;
		denominator_ /= div;
	}

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
		shorten();
	}

	void print() const {
		std::cout <<  numerator_ << "/" << denominator_;
	}

	bool operator==(Fraction f2) {
		return (numerator_ == f2.numerator_ && denominator_ == denominator_) ? true : false;
	}
	bool operator!=(Fraction f2) {
		return !(*this == f2);
	}
	bool operator<(Fraction f2) {
		return (numerator_ * f2.denominator_ < f2.numerator_ * denominator_) ? true : false;
	}
	bool operator>=(Fraction f2) {
		return !(*this < f2);
	}
	bool operator>(Fraction f2) {
		return f2 < *this;
	}
	bool operator<=(Fraction f2) {
		return !(*this > f2);
	}

	Fraction operator+(Fraction f2) {
		return Fraction(numerator_ * f2.denominator_ + f2.numerator_ * denominator_, denominator_ * f2.denominator_);
	}
	Fraction operator-(Fraction f2) {
		return Fraction(numerator_ * f2.denominator_ - f2.numerator_ * denominator_, denominator_ * f2.denominator_);
	}
	Fraction operator*(Fraction f2) {
		return Fraction(numerator_ * f2.numerator_, denominator_ * f2.denominator_);
	}
	Fraction operator/(Fraction f2) {
		return Fraction(numerator_ * f2.denominator_, denominator_ * f2.numerator_);
	}
	Fraction& operator-() {
		numerator_ = -numerator_;
		return *this;
	}
	Fraction& operator++() {
		numerator_ += denominator_;
		return *this;
	}
	Fraction operator++(int) {
		Fraction tmp(numerator_, denominator_);
		numerator_ += denominator_;
		return tmp;
	}
	Fraction& operator--() {
		numerator_ -= denominator_;
		return *this;
	}
	Fraction operator--(int) {
		Fraction tmp(numerator_, denominator_);
		numerator_ -= denominator_;
		return tmp;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	int num, den;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> num;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> den;
	Fraction fr1(num, den);
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> num;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> den;
	Fraction fr2(num, den);

	Fraction fr3 = fr1 + fr2;
	fr1.print();
	std::cout << " + ";
	fr2.print();
	std::cout << " = ";
	fr3.print();
	std::cout << std::endl;

	fr3 = fr1 - fr2;
	fr1.print();
	std::cout << " - ";
	fr2.print();
	std::cout << " = ";
	fr3.print();
	std::cout << std::endl;

	fr3 = fr1 * fr2;
	fr1.print();
	std::cout << " * ";
	fr2.print();
	std::cout << " = ";
	fr3.print();
	std::cout << std::endl;

	fr3 = fr1 / fr2;
	fr1.print();
	std::cout << " / ";
	fr2.print();
	std::cout << " = ";
	fr3.print();
	std::cout << std::endl;
	
	std::cout << "++";
	fr1.print();
	std::cout << " * ";
	fr2.print();
	std::cout << " = ";
	fr3 = ++fr1 * fr2;
	fr3.print();
	std::cout << std::endl;

	std::cout << "Значение дроби 1: ";
	fr1.print();
	std::cout << std::endl;
	
	fr1.print();
	std::cout << "-- ";
	std::cout << " * ";
	fr2.print();
	std::cout << " = ";
	fr3 = fr1-- * fr2;
	fr3.print();
	std::cout << std::endl;

	std::cout << "Значение дроби 1: ";
	fr1.print();
	std::cout << std::endl;
	return 0;
}