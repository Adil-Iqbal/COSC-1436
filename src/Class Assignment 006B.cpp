// Prints an inverted pyramid.

#include <iostream>
using namespace std;

int main()
{
	int n, r, c;
	cout << "Input number: ";
	cin >> n;
	cout << endl;

	for (r = n; r >= 1; r--)
	{
		for (c = 1; c <= r; c++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;
}