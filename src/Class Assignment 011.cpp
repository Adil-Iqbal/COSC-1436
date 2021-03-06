// Refactor class assignment 010 to include multi-dimensional arrays.

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
void write(string name[ROW_SIZE], int grade[ROW_SIZE][COL_SIZE]);
void close();

// File Declarations
ifstream inNameFile, inGradeFile;
ofstream outRecordFile;


int main()
{
	string name[ROW_SIZE];
	int grade[ROW_SIZE][COL_SIZE];

	open();
	read(name, grade);
	write(name, grade);
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

void write(string name[ROW_SIZE], int grade[ROW_SIZE][COL_SIZE])
{
	outRecordFile << noshowpoint << setprecision(0);
	for (int i = 0; i < ROW_SIZE; i++)
	{
		outRecordFile << left << setw(18) << name[i];
		cout << "Writing data: " << name[i] << endl;

		for (int j = 0; j < COL_SIZE; j++)
		{
			outRecordFile << right << setw(5) << grade[i][j];
			cout << "Writing data: " << grade[i][j] << endl;
		}
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
