/*********************************************************************
 ** Author: Rob Navarro
 ** Date: April 5, 2015
 ** Description: A program that allows the requires the player to guess a number
 *********************************************************************/

#include <iostream>
using namespace std;

int main()
{
// Create variables that will be used by both the user and the player.
// The bool will be used so that the while loop will run until the correct answer is found.

    int userInput, userGuess, guesses = 0;
    bool correctGuess = false;

// Prompt the user to enter a number that will be guessed and store it.

    cout << "Enter a number for the player to guess." << endl;
    cin >> userInput;

// Use a while loop so that the player can continue guessing until the find the correct answer
// The int "guesses" will store the number of guesses it takes to find the correct answer

    while (!correctGuess) {
       cout << "Enter your guess." << endl;
        cin >> userGuess;
        if (userGuess < userInput){
            cout << "higher" << endl;
            guesses++;
        }
        else if (userGuess > userInput) {
            cout << "lower" << endl;
            guesses++;
        }
        else {
            correctGuess = true;
            guesses++;
        }
    }

// Once the correct answer is found, display how many tries it took to solve.

    cout << "You guessed it in " << guesses << " tries.";

    return 0;
}
