#include <iostream>
#include <cstdlib> // For rand() and srand() functions
#include <ctime>   // For time() function to seed the random number generator
using namespace std;
int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;

    int userGuess;
    bool guessedCorrectly = false;

    cout << "Guess the random number between 1 and 100." << endl;

    while (!guessedCorrectly) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess == randomNumber) {
            cout << "Congratulations! You guessed it correctly." << endl;
            guessedCorrectly = true;
        } else if (userGuess < randomNumber) {
            cout << "Too low, try again." << endl;
        } else {
            cout << "Too high, try again." << endl;
        }
    }

    return 0;
}
