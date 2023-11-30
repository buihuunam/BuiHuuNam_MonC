#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int MAX_SIZE = 100;

    char inputString[MAX_SIZE];

    // Input a series of single-digit numbers
    cout << "Enter a series of single-digit numbers with no separation: ";
    cin.getline(inputString, MAX_SIZE);

    int sum = 0;
    char highestDigit = '0';
    char lowestDigit = '9';

    // Calculate the sum, highest, and lowest digits
    for (int i = 0; inputString[i] != '\0'; ++i) {
        if (isdigit(inputString[i])) {
            int digit = inputString[i] - '0';
            sum += digit;

            if (inputString[i] > highestDigit) {
                highestDigit = inputString[i];
            }

            if (inputString[i] < lowestDigit) {
                lowestDigit = inputString[i];
            }
        } else {
            cout << "Invalid input. Please enter only single-digit numbers." << endl;
            return 1; // Exit the program with an error code
        }
    }

    // Display the sum, highest, and lowest digits
    cout << "Sum of single-digit numbers: " << sum << endl;
    cout << "Highest digit: " << highestDigit << endl;
    cout << "Lowest digit: " << lowestDigit << endl;

    return 0;
}
