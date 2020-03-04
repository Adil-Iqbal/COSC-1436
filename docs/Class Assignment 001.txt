#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	// Variable Declarations.
	const double taxRate = 0.0825;

	const double tvPrice = 400.00; // TV
	const double vcPrice = 220.00; // VCR
	const double rcPrice = 35.20;  // Remote Control
	const double cdPrice = 300.00; // CD Player
	const double trPrice = 150.00; // Tape Recorder

	int tvQty;
	int vcQty;
	int rcQty;
	int cdQty;
	int trQty;

	double tvTotal;
	double vcTotal;
	double rcTotal;
	double cdTotal;
	double trTotal;

	double subTotal;
	double totalTax;
	double grandTotal;

	// User Input
	cout << "How many TVs would you like?" << endl;
	cin >> tvQty;

	cout << "How many VCRs would you like?" << endl;
	cin >> vcQty;

	cout << "How many Remote Controls would you like?" << endl;
	cin >> rcQty;

	cout << "How many CD Players would you like?" << endl;
	cin >> cdQty;

	cout << "How many Tape Recorders would you like?" << endl;
	cin >> trQty;

	// Process Implementation
	tvTotal = tvPrice * tvQty;
	vcTotal = vcPrice * vcQty;
	rcTotal = rcPrice * rcQty;
	cdTotal = cdPrice * cdQty;
	trTotal = trPrice * trQty;

	subTotal = tvTotal + vcTotal + rcTotal + cdTotal + trTotal;
	totalTax = subTotal * taxRate;
	grandTotal = subTotal + totalTax;

	// Program Output.
	cout << fixed << showpoint << setprecision(2);
	cout << endl;
	cout << endl;

	cout << "QTY     DESCRIPTION          UNIT PRICE     TOTAL PRICE" << endl;
	cout << "---     -----------          ----------     -----------" << endl;

	cout << left << setw(8) << tvQty << setw(21) << "TV" << setw(10) << right << tvPrice << setw(16) << tvTotal << endl;
	cout << left << setw(8) << vcQty << setw(21) << "VCR" << setw(10) << right << vcPrice << setw(16) << vcTotal << endl;
	cout << left << setw(8) << rcQty << setw(21) << "Remote Controller" << setw(10) << right << rcPrice << setw(16) << rcTotal << endl;
	cout << left << setw(8) << cdQty << setw(21) << "CD Player" << setw(10) << right << cdPrice << setw(16) << cdTotal << endl;
	cout << left << setw(8) << trQty << setw(21) << "Tape Recorder" << setw(10) << right << trPrice << setw(16) << trTotal << endl;

	cout << "                                            -----------" << endl;
	cout << "                             SUBTOTAL       " << setw(11) << subTotal << endl;
	cout << "                             TAX            " << setw(11) << totalTax << endl;
	cout << "                             TOTAL          " << setw(11) << grandTotal << endl;

	cout << endl;
	cout << endl;
	return 0;
}