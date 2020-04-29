/*************************************************************************
Student Name:   Adil Iqbal
Class:          6202-14454-COSC-1436
Schedule:       Monday, Wednesday 11:00AM - 1:40PM

Program 8 & 9
EC–8–604

Write a modular program that analyzes a year’s worth of rainfall data. In addition to main, the program should have a getData function that accepts the total rainfall for each of 12 months from the user and stores it in an array holding double numbers. It should also have four value-returning functions that compute and return to main the totalRainfall, averageRainfall, driestMonth, and wettestMonth. These last two functions return the number of the month with the lowest and highest rainfall amounts, not the amount of rain that fell those months. Notice that this month number can be used to obtain the amount of rain that fell those months. This information should be used either by main or by a displayReport function called by main to print a summary rainfall report similar to the following:

* 2019  Rain Report for Springdale County
* Total rainfall: 23.19 inches
* Average monthly rainfall: 1.93 inches
* The least rain fell in January with 0.24 inches.
* The most rain fell in April with 4.29 inches.
*************************************************************************/

#include <iostream>
#include <string>
#include <float.h>
#include <cassert>
#include <iomanip>
using namespace std;

const int M = 12;
const string months[M] = {
	"January", "February", "March", "April",
	"May", "June", "July", "August",
	"September", "October", "November", "December"
};

// Function Declarations
void getData(double data[M]);
double totalRainfall(double data[M]);
double averageRainfall(double total);
int driestMonth(double data[M]);
int wettestMonth(double data[M]);
void displayReport(double[], double, double, int, int);

int main()
{
	double data[M];
	double total;
	double average;
	int driest;
	int wettest;

	getData(data);
	total = totalRainfall(data);
	average = averageRainfall(total);
	driest = driestMonth(data);
	wettest = wettestMonth(data);
	displayReport(data, total, average, driest, wettest);

	return 0;
}

void getData(double data[M]) {
	for (int m = 0; m < M; m++) {
		cout << "How much rain fell in the month of " << months[m] << "? ";
		cin >> data[m];
	};
}

double totalRainfall(double data[M]) {
	double total = 0;
	for (int m = 0; m < M; m++)
		total += data[m];
	return total;
}

double averageRainfall(double total) {
	return total / static_cast<double>(M);
}

int driestMonth(double data[M]) {
	double minRainfall = DBL_MAX;
	int minIndex = -1;

	for (int m = 0; m < M; m++) {
		if (data[m] < minRainfall) {
			minRainfall = data[m];
			minIndex = m;
		};
	};

	assert(minIndex >= 0);
	return minIndex;
}

int wettestMonth(double data[M]) {
	double maxRainfall = -DBL_MAX;
	int maxIndex = -1;

	for (int m = 0; m < M; m++) {
		if (data[m] > maxRainfall) {
			maxRainfall = data[m];
			maxIndex = m;
		};
	};

	assert(maxIndex >= 0);
	return maxIndex;
}

void displayReport(
	double data[], double total, double average, int dry, int wet) {
	cout << showpoint << setprecision(3) << endl;
	cout << "2020 Rain Report for Harris County" << endl;
	cout << "Total Rainfall: " << total << " inches." << endl;
	cout << "Average Monthly Rainfall: " << average << " inches." << endl;
	cout << "The least rain fell in " << months[dry] << " at " << 
		data[dry] << " inches." << endl;
	cout << "The most rain fell in " << months[wet] << " at " << 
		data[wet] << " inches." << endl << endl;
}

// The above code produced the following stream data:
/*************************************************************************
How much rain fell in the month of January? 19.22
How much rain fell in the month of February? 32.12
How much rain fell in the month of March? 33.65
How much rain fell in the month of April? 65.44
How much rain fell in the month of May? 54.19
How much rain fell in the month of June? 98.02
How much rain fell in the month of July? 75.11
How much rain fell in the month of August? 49.13
How much rain fell in the month of September? 31.51
How much rain fell in the month of October? 26.12
How much rain fell in the month of November? 26.64
How much rain fell in the month of December? 36.86

2020 Rain Report for Harris County
Total Rainfall: 548.00 inches.
Average Monthly Rainfall: 45.70 inches.
The least rain fell in January at 19.20 inches.
The most rain fell in June at 98.00 inches.
*************************************************************************/

