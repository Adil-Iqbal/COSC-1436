#include <iostream>
using namespace std;

int main() {
	int totalSurveyed = 16500;

	double percentageEnergyDrink = 0.15;
	double percentageCitrusDrink = 0.52;

	int totalEnergyDrink;
	int totalCitrusDrink;

	totalEnergyDrink = totalSurveyed * percentageEnergyDrink;
	totalCitrusDrink = totalEnergyDrink * percentageCitrusDrink;

	cout << totalEnergyDrink << " people purchased one or more energy drink." << endl;
	cout << totalCitrusDrink << " people purchased a citrus flavored drink." << endl;

	return 0;
}