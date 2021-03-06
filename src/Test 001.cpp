/*********************************************************
Student Name:   Adil Iqbal
Class:          6202-14454-COSC-1436
Schedule:       Monday, Wednesday 11:00AM - 1:40PM

Test 1- Programming Part 

Read two integer number from an input file called input.txt, then add these two numbers , store it in a variable called TOTAL, find the difference of the two numbers , store it in Difference, find product to the two numbers , store it in a variable called Multiply, fine quotient of the two number call it Division, find modular division of them and store it in a variable called MUD.

Print input value and the result of your calculation in an out put file called  output.txt

upload all files for grading,  You will be graded based on

1. correct and workable program (15 points)

2. Good indentation and sufficient comments (10 points)
*********************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// File Declarations
ifstream inputFile;
ofstream outputFile;

int main()
{
    // Variable Declarations.
    int num1;
    int num2;
    
    int TOTAL;
    int Difference;
    int Multiply;
    int Division;
    int MUD;
    
    // Open files.
    inputFile.open("input.txt");
	outputFile.open("output.txt");
    
    // Read input integers from file.
    inputFile >> num1 >> num2;

    // Perform calculations.
    TOTAL = num1 + num2;
    Difference = num1 - num2;
    Multiply = num1 * num2;
    Division = num1 / num2;
    MUD = num1 % num2;
	
	// Print output to file.
	outputFile << num1 << " + " << num2 << " = " << TOTAL << endl;
    outputFile << num1 << " - " << num2 << " = " << Difference << endl;
    outputFile << num1 << " * " << num2 << " = " << Multiply << endl;
    outputFile << num1 << " / " << num2 << " = " << Division << endl;
    outputFile << num1 << " % " << num2 << " = " << MUD << endl;

    // Close files.
	inputFile.close();
	outputFile.close();

	return 0;
}
