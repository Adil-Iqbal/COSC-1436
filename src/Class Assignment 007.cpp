// Class Assignment 007
// Refactor Class Assignment 002 to include function calls.

#include <iostream>
#include <cassert>
using namespace std;

void getChoice(char& choice)
{
	cout << "A - Addition" << endl;
	cout << "S - Subtraction" << endl;
	cout << "M - Multiplication" << endl;
	cout << "D - Division" << endl;
	cout << "O - Modular Division\n" << endl;
	cout << "Please select one above operations (Enter A, S, M, D, or O):" << endl;
	cin >> choice;
}

void getNumbers(int& num1, int& num2)
{
	cout << "\nEnter your first integer: " << endl;
	cin >> num1;

	cout << "\nEnter your second integer: " << endl;
	cin >> num2;
}

void printOutput(int& num1, int& num2, char& sign, int& result, bool& valid)
{
	cout << "\nOUTPUT:" << endl;
	if (valid) {
		cout << num1 << " " << sign << " " << num2 << " = " << result << "\n" << endl;
	}
	else {
		cout << "\nSomething went wrong. Please try again!" << endl;
	}
}

// Function Prototypes
int sum(int a, int b, char& sign);
int diff(int a, int b, char& sign);
int mult(int a, int b, char& sign);
int div(int a, int b, char& sign);
int mod(int a, int b, char& sign);

int getResult(char& choice, int& num1, int& num2, char& sign, bool& valid)
{
	switch (choice) {
	case 'A':
	case 'a':
		return sum(num1, num2, sign);
	case 'S':
	case 's':
		return diff(num1, num2, sign);
	case 'M':
	case 'm':
		return mult(num1, num2, sign);
	case 'D':
	case 'd':
		return div(num1, num2, sign);
	case 'O':
	case 'o':
		return mod(num1, num2, sign);
	default:
		valid = false;
	}
}

int main() {
	// Variable Declaration
	bool inputIsValid = true;
	char operationChoice, operationSign;
	int number1, number2, result;

	// User Input
	getChoice(operationChoice);
	getNumbers(number1, number2);

	// Process
	result = getResult(operationChoice, number1, number2, operationSign, inputIsValid);

	// Output
	printOutput(number1, number2, operationSign, result, inputIsValid);
	return 0;
}

int sum(int a, int b, char& sign)
{
	sign = '+';
	return a + b;
}

int diff(int a, int b, char& sign)
{
	sign = '-';
	return a - b;
}

int mult(int a, int b, char& sign)
{
	sign = '*';
	return a * b;
}

int div(int a, int b, char& sign)
{
	assert(b != 0);
	sign = '/';
	return a / b;
}

int mod(int a, int b, char& sign)
{
	sign = '%';
	return a % b;
}
