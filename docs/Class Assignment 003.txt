#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout << "\n===== Quadratic Equation Calculator =====" << endl;

	double a, b, c;
	cout << "\nEnter coefficient A: " << endl;
	cin >> a;
	cout << "\nEnter coefficient B: " << endl;
	cin >> b;
	cout << "\nEnter coefficient C: " << endl;
	cin >> c;

	cout << "\nSolution(s):" << endl;

	const double real = -b / 2 * a;
	const double disc = b * b - 4 * a * c;

	if (disc == 0) {
		cout << real << endl;
	}
	else if (disc > 0) {
		const double r1 = (-b + sqrt(disc)) / 2 * a;
		const double r2 = (-b - sqrt(disc)) / 2 * a;
		cout << r1 << endl;
		cout << r2 << endl;
	}
	else {
		const double imaginary = sqrt(-disc) / 2 * a;
		cout << real << " + " << imaginary << "i" << endl;
		cout << real << " - " << imaginary << "i" << endl;
	}

	cout << "" << endl;
	system("pause");
	return 0;
}