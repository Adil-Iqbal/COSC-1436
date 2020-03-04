#include <iostream>
#include <string>
using namespace std;

// Function Declaration.
void failSafe();
double inputIsValid();

int main()
{
	const int IN_PATIENT = 1;
	const int OUT_PATIENT = 2;

	string prompt;
	signed int choice = -1;

	cout << "1. Inpatient" << endl;
	cout << "2. Outpatient" << endl;
	prompt = "How were you treated? (Enter 1 or 2): ";

	// See footnote #1.
	choice = static_cast<int>(inputIsValid(static_cast<double>(choice), prompt));

	cout << endl;

	if (choice == IN_PATIENT)
	{

	}

	else if (choice == OUT_PATIENT)
	{

	}

	// See footnote #2.
	else
	{
		cout << "Please try again. Enter either 1 or 2." << endl;
		return 0;
	}

	cout << choice;
	return 0;
}

double inputIsValid(double input, string prompt)
{
	do {
		failSafe();
		cout << prompt;
		cin >> input;
	} while (input < 0);

	return input;
}

// See footnote #3
void failSafe()
{
	if (cin.fail())
	{

	}
}


/*
-- Footnote 1 --
This assignment requires that a single, separate function should validate that no input is less than zero. Since the choice variable is an integer and the input validation function expects a double and returns a double; my solution was to cast the choice integer as a double, and then cast the return value as an integer. In a real world senario, this particular statement may get its own do-while loop. Or perhaps, the input validation function would be overloaded so as to handle both integers and doubles.

-- Footnote 2 --
Though the choice integer

be less than zero, we cannot be sure that it will be either 1 or 2. Perhaps, the user may input a value of 99. This else statement will catch and handle that error.

-- Footnote 3 --
Though this function was not required by the assignment, it was included to ensure that nonsense input by the user would not cause a stream failure.

*/