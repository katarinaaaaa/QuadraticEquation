#include <iostream>
#include <cmath>
using namespace std;

class QuadraticEquation {
public:
	double a;
	double b;
	double c;

	void GetCoefficients() {
		while (true) {
			cout << "Enter the value of the coefficient a: ";
			cin >> a;
			if (!cin || cin.peek() != '\n') {
				cout << "Incorrect input. Please, enter correct value." << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
			else
				break;
		}
		while (true) {
			cout << "Enter the value of the coefficient b: ";
			cin >> b;
			if (!cin || cin.peek() != '\n') {
				cout << "Incorrect input. Please, enter correct value." << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
			else
				break;
		}
		while (true) {
			cout << "Enter the value of the coefficient c: ";
			cin >> c;
			if (!cin || cin.peek() != '\n') {
				cout << "Incorrect input. Please, enter correct value." << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
			else
				break;
		}
	}

	void PrintEquation() {
		cout << a << "x^2 + ";
		if (b < 0)
			cout << "(" << b << ")";
		else
			cout << b;
		cout << "x + ";
		if (c < 0)
			cout << "(" << c << ")";
		else
			cout << c;
		cout << " = 0";
	}

	double Discriminant() {
		double d;
		d = (b * b - 4 * a * c);
		return d;
	}

	void PrintRoots() {
		cout << "The roots of equation ";
		PrintEquation();
		cout << " : ";

		if (a == 0) {
			if (b == 0 && c == 0)
				cout << "all numbers" << endl;
			else if (b == 0 && c != 0)
				cout << "no real roots" << endl;
			else {
				double x1 = - c / b;
				cout << x1;
			}
		}
		else {
			double d = Discriminant();
			if (d < 0)
				cout << "no real roots" << endl;
			else if (d == 0) {
				double x1 = -b / (2 * a);
				cout << x1 << endl;
			}
			else {
				double x1 = (-b + sqrt(d)) / (2 * a);
				double x2 = (-b - sqrt(d)) / (2 * a);
				if (x1 > x2)
					cout << x1 << " " << x2 << endl;
				else
					cout << x2 << " " << x1 << endl;
			}
		}
	}
};

int main () {
	QuadraticEquation equation;
	equation.GetCoefficients();
	equation.PrintRoots();
	return 0;
}
