/*
Student Name:   Adil Iqbal
Class:          6202-14454-COSC-1436
Schedule:       Monday, Wednesday 11:00AM - 1:40PM

Assignment 4 & Program 4
22-245-10E
Random Number Guessing Game Write a program that generates a random number between 1 and 100 and asks the user to guess what the number is. If the user’s guess is higher than the random number, the program should display “Too high. Try again.” If the user’s guess is lower than the random number, the program should display “Too low. Try again.” The program should use a loop that repeats until the user correctly guesses the random number. Then the program should display “Congratulations. You figured out my number.”
*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(0));
    const int randomNum = rand() % 100 + 1;
    int tries = 0;
    int guess;

    do {
        cout << "Guess my number!" << endl;
        cin >> guess;
        if (guess < randomNum) {
            cout << "Too low! Try again." << endl;
        }
        else if (guess > randomNum) {
            cout << "Too high! Try again." << endl;
        }
        tries++;
    } while (guess != randomNum);

    cout << "“Congratulations. You figured out my number" << endl;
    cout << "That took you " << tries << " tries." << endl;

    return 0;
}
