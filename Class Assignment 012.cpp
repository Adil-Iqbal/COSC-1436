// Refactor class assignment 011 to include createSum and createAverage functions.

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
void write(string name[ROW_SIZE], int grade[ROW_SIZE][COL_SIZE], int sum[ROW_SIZE], double average[ROW_SIZE]);
void close();

// File Declarations
ifstream inNameFile, inGradeFile;
ofstream outRecordFile;


int main()
{
	string name[ROW_SIZE];
	int grade[ROW_SIZE][COL_SIZE];
	int sum[ROW_SIZE] = {0};
	double average[ROW_SIZE] = { 0.0 };

	open();
	read(name, grade);
	createSum(grade, sum);
	createAverage(sum, average);
	write(name, grade, sum, average);
	close();

	cout << "Task complete." << endl;
	return 0;
}

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

void createSum(int grade[ROW_SIZE][COL_SIZE], int sum[ROW_SIZE])
{
	for (int i = 0; i < ROW_SIZE; i++)
	{
		for (int j = 0; j < COL_SIZE; j++)
			sum[i] += grade[i][j];
	}
}

void createAverage(int sum[ROW_SIZE], double average[ROW_SIZE])
{
	for (int i = 0; i < ROW_SIZE; i++)
		average[i] = static_cast<double>(sum[i]) / COL_SIZE;
}

void write(string name[ROW_SIZE], int grade[ROW_SIZE][COL_SIZE], int sum[ROW_SIZE], double average[ROW_SIZE])
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

		outRecordFile << endl;
		cout << endl;
	}
}

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
