/*************************************************************************
Student Name:   Adil Iqbal
Class:          6202-14454-COSC-1436
Schedule:       Monday, Wednesday 11:00AM - 1:40PM

Test 2 - Programming Part
Write a program, that finds solution (roots) of quadratic equation, allow user to input as much as function they need, terminate program when user inputted N = No.

You need to test if function has two real solution, one real solution or imaginary solution. (5 points)

You must use functions to find roots (5 points)

You need to use proper indentations and comments (5 points)

Your program must work properly (10 points)
*************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

// Function Declarations
void userInput(double& a, double& b, double& c);
void printSolutions(double& a, double& b, double& c);
void getResponse(char& resp);


int main() {
	// Print program title.
	cout << "===== Quadratic Equation Calculator =====" << endl;

	// Declare variables.
	double a, b, c;		// Coefficients.
	char resp = 'Y';	// User response.

	// Perform tasks.
	do {
		userInput(a, b, c);
		printSolutions(a, b, c);
		getResponse(resp);
	} while (resp != 'N' && resp != 'n');

	// Terminate program.
	cout << endl;
	system("pause");
	return 0;
}

// Ask user to input coefficients.
void userInput(double& a, double& b, double& c) {
	cout << "\nEnter coefficient A: ";
	cin >> a;
	cout << "\nEnter coefficient B: ";
	cin >> b;
	cout << "\nEnter coefficient C: ";
	cin >> c;
}

// Perform calculations and print solution to stream.
void printSolutions(double& a, double& b, double& c) {
	cout << "\nSolution(s):" << endl;

	// Calculate real part and discriminant. 
	const double real = -b / 2 * a;
	const double disc = b * b - 4 * a * c;

	// One real solution.
	if (disc == 0) {
		cout << real << endl;
	}
	// Two real solutions.
	else if (disc > 0) {
		const double r1 = (-b + sqrt(disc)) / 2 * a;
		const double r2 = (-b - sqrt(disc)) / 2 * a;
		cout << r1 << endl;
		cout << r2 << endl;
	}
	// Two imaginary solutions.
	else {
		const double imaginary = sqrt(-disc) / 2 * a;
		cout << real << " + " << imaginary << "i" << endl;
		cout << real << " - " << imaginary << "i" << endl;
	}
}

// Ask user if they would like to continue.
void getResponse(char& resp) {
	cout << endl;
	cout << "Would you like to do solve another function? (Y/N): ";
	cin >> resp;
}
