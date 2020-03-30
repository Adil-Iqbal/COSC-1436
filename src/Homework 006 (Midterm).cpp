/******************************************************************
Student Name:   Adil Iqbal
Class:          6202-14454-COSC-1436
Schedule:       Monday, Wednesday 11:00AM - 1:40PM

Program 6 - Midterm Program
EO-16-409
Write a program that computes and displays the charges for a patient’s hospital stay. First, the program should ask if the patient was admitted as an inpatient or an outpatient. If the patient was an inpatient, the following data should be entered:

  * The number of days spent in the hospital
  * The daily rate
  * Charges for hospital services (lab tests, etc.)
  * Hospital medication charges
     
If the patient was an outpatient, the following data should be entered:

  * Charges for hospital services (lab tests, etc.)
  * Hospital medication charges

Use a single, separate function to validate that no input is less than zero. If it is, it should be reentered before being returned. Once the required data has been input and validated, the program should use two overloaded functions to calculate the total charges. One of the functions should accept arguments for the inpatient data, while the other function accepts arguments for outpatient data. Both functions should return the total charges”
******************************************************************/

#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

// Function declaration
double aboveZero(string prompt);
double totalCost(double days, double dailyRate, double hospServ, double drugCost);
double totalCost(double hospServ, double drugCost);

int main() 
{
  // Variable declaration.
  char resp;
  double days = 0.0;
  double dailyRate = 0.0;
  double hospServ = 0.0;
  double drugCost = 0.0;
    
  do // Inpatient or outpatient?
  {
    cout << "Were you admitted as inpatient? (Y or N): ";
    cin >> resp;
    resp = toupper(resp); // Allows 'n' and 'y' to be valid inputs.
  } while (resp != 'Y' && resp != 'N');

  if (resp == 'Y') // If inpatient...
  {
    days = aboveZero("How many days did you spend in the hospital? (Enter a number): ");
    dailyRate = aboveZero("What was the daily rate? (Enter an dollar amount): ");
  }

  /* The inputs below are common to both inpatient and outpatient cases. */
  hospServ = aboveZero("What were the charges for hospital services? (Enter an dollar amount): ");
  drugCost = aboveZero("What were the charges for medication? (Enter an dollar amount): ");

  if (resp == 'Y') // If inpatient...
  {
    cout << totalCost(days, dailyRate, hospServ, drugCost) << endl;
    return 0;
  }
  
  /* If inpatient, the main function will return before the code below is executed. */
  cout << totalCost(hospServ, drugCost) << endl;
  return 0;
}

// Validates that all inputs are above zero.
double aboveZero(string prompt)
{
  double variable;
  do {
    cout << prompt; 
    cin >> variable;
  } while (variable < 0);
  return variable;
}

// Outpatient overloaded function.
double totalCost(double hospServ, double drugCost)
{
  return hospServ + drugCost;
}

// Inpatient overloaded function.
double totalCost(double days, double dailyRate, double hospServ, double drugCost)
{
  return days * dailyRate + hospServ + drugCost;
}
