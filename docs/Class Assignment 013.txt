// Refactor class assignment 012 so students can be sorted by name or letter grade.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int ROW_SIZE = 7;
const int COL_SIZE = 7;

// Function Declarations
void open();
void read(string name[ROW_SIZE], int grade[ROW_SIZE][COL_SIZE]);
void createSum(int grade[ROW_SIZE][COL_SIZE], int sum[ROW_SIZE]);
void createAverage(int sum[ROW_SIZE], double average[ROW_SIZE]);
void createLetterGrade(double average[ROW_SIZE], char letter[ROW_SIZE]);
void sortByLetterGrade(string name[ROW_SIZE], int grade[ROW_SIZE][COL_SIZE], int sum[ROW_SIZE], double average[ROW_SIZE], char letter[ROW_SIZE]);
void sortByName(string name[ROW_SIZE], int grade[ROW_SIZE][COL_SIZE], int sum[ROW_SIZE], double average[ROW_SIZE], char letter[ROW_SIZE]);
void write(string name[ROW_SIZE], int grade[ROW_SIZE][COL_SIZE], int sum[ROW_SIZE], double average[ROW_SIZE], char letter[ROW_SIZE]);
void close();

// File Declarations
ifstream inNameFile, inGradeFile;
ofstream outRecordFile;

/* Main program. */
int main()
{
	string name[ROW_SIZE];
	int grade[ROW_SIZE][COL_SIZE];
	int sum[ROW_SIZE] = {0};
	double average[ROW_SIZE] = { 0.0 };
	char letter[ROW_SIZE];

	open();
	read(name, grade);
	createSum(grade, sum);
	createAverage(sum, average);
	createLetterGrade(average, letter);
	// sortByLetterGrade(name, grade, sum, average, letter);
	sortByName(name, grade, sum, average, letter);
	write(name, grade, sum, average, letter);
	close();

	cout << "Task complete." << endl;
	return 0;
}

/* Open all relevant input files. */
void open()
{
	string fileStname = "stname.txt";
	string fileStgrade = "stgrade.txt";
	string fileStrecord = "strecord.txt";

	inNameFile.open(fileStname);
	cout << "Accessed file: " << fileStname << endl;

	inGradeFile.open(fileStgrade);
	cout << "Accessed file: " << fileStgrade << endl;

	outRecordFile.open("strecord.txt");
	cout << "Accessed file: " << fileStrecord << endl;

	cout << endl;
}

/* Store input file data in local arrays. */
void read(string name[ROW_SIZE], int grade[ROW_SIZE][COL_SIZE])
{
	for (int i = 0; i < ROW_SIZE; i++)
	{
		getline(inNameFile, name[i]);
		cout << "Retrieved data: " << name[i] << endl;

		for (int j = 0; j < COL_SIZE; j++)
		{
			inGradeFile >> grade[i][j];
			cout << "Retrieved data: " << grade[i][j] << endl;
		}
		cout << endl;
	}
	cout << endl;
}

/* Figure out raw total from the individual test scores. */
void createSum(int grade[ROW_SIZE][COL_SIZE], int sum[ROW_SIZE])
{
	for (int i = 0; i < ROW_SIZE; i++)
	{
		for (int j = 0; j < COL_SIZE; j++)
			sum[i] += grade[i][j];
	}
}

/* Figure out average grade from the raw total. */
void createAverage(int sum[ROW_SIZE], double average[ROW_SIZE])
{
	for (int i = 0; i < ROW_SIZE; i++)
		average[i] = static_cast<double>(sum[i]) / COL_SIZE;
}

/* Calculate letter grade from averages. */
void createLetterGrade(double average[ROW_SIZE], char letter[ROW_SIZE])
{
	for (int i = 0; i < ROW_SIZE; i++)
	{
		if (average[i] >= 90)
			letter[i] = 'A';
		else if (average[i] >= 80)
			letter[i] = 'B';
		else if (average[i] >= 70)
			letter[i] = 'C';
		else if (average[i] >= 65)
			letter[i] = 'D';
		else
			letter[i] = 'F';
	}
}

/* Swap student at position (i) with student at position (i + 1). */
void swap(int i, string name[ROW_SIZE], int grade[ROW_SIZE][COL_SIZE], int sum[ROW_SIZE], double average[ROW_SIZE], char letter[ROW_SIZE])
{
	int j = i + 1;

	// Create temporary variables that store 1st student.
	string tempName = name[i];
	int tempGrade[ROW_SIZE];
	for (int g = 0; g < COL_SIZE; g++)
		tempGrade[g] = grade[i][g];
	int tempSum = sum[i];
	double tempAverage = average[i];
	char tempLetter = letter[i];

	// Overwrite 1st student with 2nd student.
	name[i] = name[j];
	for (int g = 0; g < COL_SIZE; g++)
		grade[i][g] = grade[j][g];
	sum[i] = sum[j];
	average[i] = average[j];
	letter[i] = letter[j];

	// Overwrite 2nd student with temporary variable.
	name[j] = tempName;
	for (int g = 0; g < COL_SIZE; g++)
		grade[j][g] = tempGrade[g];
	sum[j] = tempSum;
	average[j] = tempAverage;
	letter[j] = tempLetter;
}

/* Sort students by letter grade. */
void sortByLetterGrade(string name[ROW_SIZE], int grade[ROW_SIZE][COL_SIZE], int sum[ROW_SIZE], double average[ROW_SIZE], char letter[ROW_SIZE])
{
	cout << "Sorting students by letter grade..." << endl;
	for (int i = 0; i < ROW_SIZE - 1; i++)
	{
		for (int j = 0; j < ROW_SIZE - i - 1; j++) {
			if (letter[j] > letter[j + 1])
				swap(j, name, grade, sum, average, letter);
		}
	}
	cout << endl;
}

/* Sort students by name. */
void sortByName(string name[ROW_SIZE], int grade[ROW_SIZE][COL_SIZE], int sum[ROW_SIZE], double average[ROW_SIZE], char letter[ROW_SIZE])
{
	cout << "Sorting students by letter grade..." << endl;
	for (int i = 0; i < ROW_SIZE - 1; i++)
	{
		for (int j = 0; j < ROW_SIZE - i - 1; j++) {
			if (name[j] > name[j + 1])
				swap(j, name, grade, sum, average, letter);
		}
	}
	cout << endl;
}

/* Write data to the output file. */
void write(string name[ROW_SIZE], int grade[ROW_SIZE][COL_SIZE], int sum[ROW_SIZE], double average[ROW_SIZE], char letter[ROW_SIZE])
{
	const int NAME_WIDTH = 18;
	const int GRADE_WIDTH = 10;

	outRecordFile << noshowpoint << setprecision(0);

	// File Header
	outRecordFile << left << setw(NAME_WIDTH) << "STUDENT NAME";
	for (int i = 0; i < COL_SIZE; i++)
		outRecordFile << right << setw(GRADE_WIDTH) << "TEST " + to_string(i);
	outRecordFile << right << setw(GRADE_WIDTH) << "TOTAL";
	outRecordFile << right << setw(GRADE_WIDTH) << "AVERAGE";
	outRecordFile << right << setw(GRADE_WIDTH) << "GRADE";
	outRecordFile << endl;

	// File Body
	for (int i = 0; i < ROW_SIZE; i++)
	{
		// File Body - Student Names
		outRecordFile << left << setw(NAME_WIDTH) << name[i];
		cout << "Writing data: " << name[i] << endl;

		// File Body - Student Grades
		for (int j = 0; j < COL_SIZE; j++)
		{
			outRecordFile << right << setw(GRADE_WIDTH) << grade[i][j];
			cout << "Writing data: " << grade[i][j] << endl;
		}

		// File Body - Student Totals
		outRecordFile << right << setw(GRADE_WIDTH) << sum[i];
		cout << "Writing data: " << sum[i] << endl;

		// File Body - Student Averages
		outRecordFile << setprecision(4) << right << setw(GRADE_WIDTH) << average[i];
		cout << "Writing data: " << average[i] << endl;

		// File Body - Letter Grade
		outRecordFile << setprecision(4) << right << setw(GRADE_WIDTH) << letter[i];
		cout << "Writing data: " << letter[i] << endl;

		outRecordFile << endl;
		cout << endl;
	}
}

/* Close all relevant files. */
void close()
{
	string fileStname = "stname.txt";
	string fileStgrade = "stgrade.txt";
	string fileStrecord = "strecord.txt";

	inNameFile.close();
	cout << "Closed file: " << fileStname << endl;

	inGradeFile.close();
	cout << "Closed file: " << fileStgrade << endl;

	outRecordFile.close();
	cout << "Closed file: " << fileStrecord << endl;

	cout << endl;
}
