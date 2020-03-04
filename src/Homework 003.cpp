/*
Student Name: 	Adil Iqbal
Class: 		6202-14454-COSC-1436
Schedule: 	Monday, Wednesday 11:00a - 1:40p

Assignment 3 & Program 3
22-245-10E
A mobile phone service has three different data plans for its customers:

PLAN A: For $19.99 per month, 2 gigabytes are provided. Additional usage costs $8.00 per gigabyte.
PLAN B: For $59.99 per month, 8 gigabytes are provided. Additional usage costs $8.00 per gigabyte.
PLAN C: For $79.99 per month, Unlimited data is provided.

Write a program that calculates a customer’s monthly bill. It should input the customer name, which plan was purchased, and how many gigabytes were used. It should then create a bill that includes the input information and the total amount due. It should also display how much money plan A customers would save if they purchased plan B or C, and how much money plan B customers would save if they purchased plan C. If there would be no savings, no message should be printed. Wherever possible, use named constants instead of numbers.
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

int main() {
	// Variable Declarations.

	string customerName;
	char plan;
	int dataUsed;

	const int includedDataOfPlanA = 2;
	const int includedDataOfPlanB = 8;

	int extraDataOfPlanA;
	int extraDataOfPlanB;

	const double baseCostOfPlanA = 19.99;
	const double baseCostOfPlanB = 59.99;

	const double pricePerAdditionalGB = 8;
	double extraCostOfPlanA;
	double extraCostOfPlanB;

	double totalPriceOfPlanA;
	double totalPriceOfPlanB;
	const double totalPriceOfPlanC = 79.99;

	const double taxRate = 0.0825;
	double subTotal;
	double taxDue;
	double totalCost;

	double savingsB;
	double savingsC;


	// User Input
	cout << "What is your name?" << endl;
	getline(cin, customerName);

	cout << "\nPLAN A: For $19.99 per month, 2 gigabytes are provided. Additional usage costs $8.00 per gigabyte." << endl;
	cout << "PLAN B: For $59.99 per month, 8 gigabytes are provided. Additional usage costs $8.00 per gigabyte." << endl;
	cout << "PLAN C: For $79.99 per month, Unlimited data is provided.\n" << endl;
	cout << "What plan would you like to purchase (Enter A, B, or C)?" << endl;
	cin >> plan;
	plan = toupper(plan);

	cout << "\nHow much gigabytes of data would you typically use per month?" << endl;
	cin >> dataUsed;

	// Process
	extraDataOfPlanA = dataUsed - includedDataOfPlanA;
	extraDataOfPlanB = dataUsed - includedDataOfPlanB;
	extraCostOfPlanA = extraDataOfPlanA * pricePerAdditionalGB;
	extraCostOfPlanB = extraDataOfPlanB * pricePerAdditionalGB;
	totalPriceOfPlanA = extraCostOfPlanA + baseCostOfPlanA;
	totalPriceOfPlanB = extraCostOfPlanB + baseCostOfPlanB;

	if (plan == 'A') {
		subTotal = totalPriceOfPlanA;
	}
	else if (plan == 'B') {
		subTotal = totalPriceOfPlanB;
	}
	else if (plan == 'C') {
		subTotal = totalPriceOfPlanC;
	}
	else {
		subTotal = 0;
	}

	savingsB = subTotal - totalPriceOfPlanB;
	savingsC = subTotal - totalPriceOfPlanC;

	taxDue = subTotal * taxRate;
	totalCost = subTotal + taxDue;

	// Output
	//
	// The following code generated this sample output:
	// 
	// ---------------------------------
	// Customer Name          Adil Iqbal
	// Selected Plan              Plan B
	// 
	// Included Data                8 GB
	// Additional Data Used         6 GB
	// Total Data Used             14 GB
	// 
	// Plan Cost            $      59.99
	// Additional Data Cost $      48.00
	// ---------------------------------
	// 	       SUBTOTAL $     107.99
	// 	        TAX DUE $       8.91
	// 	     TOTAL COST $     116.90
	// ---------------------------------
	// 
	// You can save $28.00 by switching to Plan C!
	//


	if (subTotal == 0 || dataUsed == 0) {
		cerr << "\n\nSomething went wrong. Please try again." << endl;
	}
	else {
		const int columnA = 21;
		const int columnB = 2;
		const int columnC = 10;
		const string lineBreak(columnA + columnB + columnC, '-');


		cout << fixed << showpoint << setprecision(2);
		cout << setw(columnA + columnC) << "\n" + lineBreak << endl;
		cout << left << setw(columnA) << "Customer Name" << setw(columnB) << "" << right << setw(columnC) << customerName << endl;

		if (plan == 'A') {
			cout << left << setw(columnA) << "Selected Plan" << setw(columnB) << "" << right << setw(columnC) << "Plan A" << endl;
			cout << endl;
			cout << left << setw(columnA) << "Included Data" << setw(columnB) << "" << right << setw(columnC) << to_string(includedDataOfPlanA) + " GB" << endl;
			cout << left << setw(columnA) << "Additional Data Used" << setw(columnB) << "" << right << setw(columnC) << to_string(extraDataOfPlanA) + " GB" << endl;
		}
		else if (plan == 'B') {
			cout << left << setw(columnA) << "Selected Plan" << setw(columnB) << "" << right << setw(columnC) << "Plan B" << endl;
			cout << endl;
			cout << left << setw(columnA) << "Included Data" << setw(columnB) << "" << right << setw(columnC) << to_string(includedDataOfPlanB) + " GB" << endl;
			cout << left << setw(columnA) << "Additional Data Used" << setw(columnB) << "" << right << setw(columnC) << to_string(extraDataOfPlanB) + " GB" << endl;
		}
		else if (plan == 'C') {
			cout << left << setw(columnA) << "Selected Plan" << setw(columnB) << "" << right << setw(columnC) << "Plan C" << endl;
			cout << endl;
			cout << left << setw(columnA) << "Included Data" << setw(columnB) << "" << right << setw(columnC) << "Unlimited" << endl;
			cout << left << setw(columnA) << "Additional Data Used" << setw(columnB) << "" << right << setw(columnC) << "0 GB" << endl;
		}
		cout << left << setw(columnA) << "Total Data Used" << setw(columnB) << "" << right << setw(columnC) << to_string(dataUsed) + " GB" << endl;
		cout << endl;
		if (plan == 'A') {
			cout << left << setw(columnA) << "Plan Cost" << setw(columnB) << "$ " << right << setw(columnC) << baseCostOfPlanA << endl;
			cout << left << setw(columnA) << "Additional Data Cost" << right << setw(columnC) << extraCostOfPlanA << endl;
		}
		else if (plan == 'B') {
			cout << left << setw(columnA) << "Plan Cost" << setw(columnB) << "$ " << right << setw(columnC) << baseCostOfPlanB << endl;
			cout << left << setw(columnA) << "Additional Data Cost" << setw(columnB) << "$ " << right << setw(columnC) << extraCostOfPlanB << endl;
		}
		else if (plan == 'C') {
			cout << left << setw(columnA) << "Plan Cost" << setw(columnB) << "$ " << right << setw(columnC) << totalPriceOfPlanC << endl;
			cout << left << setw(columnA) << "Additional Data Cost" << setw(columnB) << "$ " << right << setw(columnC) << 0 << endl;
		}
		cout << setw(columnA + columnC) << lineBreak << endl;
		cout << right << setw(columnA) << "SUBTOTAL " << setw(columnB) << "$ " << setw(columnC) << subTotal << endl;
		cout << right << setw(columnA) << "TAX DUE " << setw(columnB) << "$ " << setw(columnC) << taxDue << endl;
		cout << right << setw(columnA) << "TOTAL COST " << setw(columnB) << "$ " << setw(columnC) << totalCost << endl;
		cout << setw(columnA + columnC) << lineBreak + "\n" << endl;

		if (plan != 'B' && savingsB > 0) {
			cout << "You can save $" << savingsB << " by switching to Plan B!" << endl;
		}
		if (plan != 'C' && savingsC > 0) {
			cout << "You can save $" << savingsC << " by switching to Plan C!" << endl;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
