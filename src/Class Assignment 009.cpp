#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function Declarations
void read(string& name, int& grade);
void write(string& name, int& grade);
void close();

// File Declarations
ifstream inNameFile, inGradeFile;
ofstream outRecordFile;

int main()
{
	string name;
	int grade;

	read(name, grade);
	write(name, grade);
	close();

	cout << "Task complete." << endl;
	return 0;
}

void read(string& name, int& grade)
{
	string fileStname = "stname.txt";
	string fileStgrade = "stgrade.txt";

	inNameFile.open(fileStname);
	cout << "Accessed file: " << fileStname << endl;

	getline(inNameFile, name);
	cout << "Retrieved data: " << name << endl;
	cout << endl;

	inGradeFile.open(fileStgrade);
	cout << "Accessed file: " << fileStgrade << endl;

	inGradeFile >> grade;
	cout << "Retrieved data: " << grade << endl;
	cout << endl;
}

void write(string& name, int& grade)
{
	string fileStrecord = "strecord.txt";

	outRecordFile.open("strecord.txt");
	cout << "Accessed file: " << fileStrecord << endl;

	string data = name + " " + to_string(grade);
	outRecordFile << data << endl;
	cout << "Writing data: " << data << endl;
	cout << endl;
}

void close()
{
	inNameFile.close();
	inGradeFile.close();
	outRecordFile.close();
	cout << "Closed all files." << endl;
	cout << endl;
}