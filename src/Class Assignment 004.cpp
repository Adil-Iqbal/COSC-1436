/*
Factorial Calculator
1. Asks user to input a positive integer.
2. Validate input.
3. Print the factorial value of that integer.
*/

#include <iostream>
using namespace std;

int main() {
	long unsigned int num;
	double fact = 1;
	char resp;
	int i;

	cout << "====================" << endl;
	cout << "Factorial Calculator" << endl;
	cout << "====================" << endl;

	do {
		cout << "\nPlease input a positive integer: " << endl;
		cin >> num;

		if (num < 0) {
			cout << "\nYour number is less than zero." << endl;
		}
		else if (num == 0 || num == 1) {
			cout << "\n" << num << "! = " << 1 << endl;
		}
		else {
			for (int i = 1; i <= num; i++) {
				fact = fact * i;
			}
			cout << "\n" << num << "! = " << fact << endl;
		}

		cout << "\nDo you want to try again? (Y = Yes)" << endl;
		cin >> resp;
	} while (resp == 'Y' || resp == 'y');
}