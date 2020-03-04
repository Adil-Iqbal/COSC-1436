/*
Student Name: Adil Iqbal
Class: 6202-COSC-1436
Schedule: Monday & Wednesday 11:00AM - 1:40PM

Assignment 2 & Program 2
24-155-10E

Write a program that asks the user for an angle, entered in radians. The program should then display the sine, cosine, and tangent of the angle.  (Use the sin, cos, and tan library functions to determine these values.)  The output should be displayed in fixed –point notation, rounded to four decimal places of precision.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	// Variable Declarations
	double radians;
	double sinAnswer;
	double cosAnswer;
	double tanAnswer;

	// User Input
	cout << "Enter an angle in radians: " << endl;
	cin >> radians;

	// Process
	sinAnswer = sin(radians);
	cosAnswer = cos(radians);
	tanAnswer = tan(radians);

	// Output
	cout << fixed << showpoint << setprecision(4);
	cout << "" << endl;
	cout << "The sine of your angle is " << sinAnswer << "." << endl;
	cout << "The cosine of your angle is " << cosAnswer << "." << endl;
	cout << "The tangent of your angle is " << tanAnswer << "." << endl;

	return 0;
}