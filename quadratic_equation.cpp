#include <iostream>
#include <cmath>

class QuadraticEquation {
public:
	double a;
	double b;
	double c;

	void GetCoefficient(double* coef, char name) {
		while (true) { //the loop repeats until the correct value is read
			std::cout << "Enter the value of the coefficient " << name << ": ";
			std::cin >> *coef;
			if (!std::cin || std::cin.peek() != '\n') { //if an invalid value is read
				std::cout << "Incorrect input. Please, enter correct value." << std::endl;
				std::cin.clear(); //clear the error flag
				while (std::cin.get() != '\n'); //read all the characters up to the end of the line to clean input
			}
			else //if a correct value is collected
				break;
		}
	}

	void GetEquation() {
		GetCoefficient(&a, 'a');
		GetCoefficient(&b, 'b');
		GetCoefficient(&c, 'c');
	}

	void PrintEquation() {
		std::cout << a << "x^2 + ";
		if (b < 0)
			std::cout << "(" << b << ")";
		else
			std::cout << b;
		std::cout << "x + ";
		if (c < 0)
			std::cout << "(" << c << ")";
		else
			std::cout << c;
		std::cout << " = 0";
	}

	double Discriminant() {
		double d;
		d = (b * b - 4 * a * c);
		return d;
	}

	void PrintRoots() {
		std::cout << "The roots of equation ";
		PrintEquation();
		std::cout << " : ";

		if (a == 0) {
			if (b == 0 && c == 0)
				std::cout << "all numbers" << std::endl;
			else if (b == 0 && c != 0)
				std::cout << "no real roots" << std::endl;
			else {
				double x1 = - c / b;
				std::cout << x1;
			}
		}
		else {
			double d = Discriminant();
			if (d < 0)
				std::cout << "no real roots" << std::endl;
			else if (d == 0) {
				double x1 = -b / (2 * a);
				std::cout << x1 << std::endl;
			}
			else {
				double x1 = (-b + sqrt(d)) / (2 * a);
				double x2 = (-b - sqrt(d)) / (2 * a);
				if (x1 > x2)
					std::cout << x1 << " " << x2 << std::endl;
				else
					std::cout << x2 << " " << x1 << std::endl;
			}
		}
	}
};

int main () {
	QuadraticEquation equation;
	equation.GetEquation();
	equation.PrintRoots();
	return 0;
}
