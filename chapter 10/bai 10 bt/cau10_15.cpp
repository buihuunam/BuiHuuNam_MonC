#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    ifstream inputFile("Chapter10/text.txt");

    // Check if the file is successfully opened
    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    char ch;
    int uppercaseCount = 0;
    int lowercaseCount = 0;
    int digitCount = 0;

    // Read characters from the file
    while (inputFile.get(ch)) {
        if (isupper(ch)) {
            uppercaseCount++;
        } else if (islower(ch)) {
            lowercaseCount++;
        } else if (isdigit(ch)) {
            digitCount++;
        }
    }

    // Close the file
    inputFile.close();

    // Display the results
    cout << "Number of uppercase letters: " << uppercaseCount << endl;
    cout << "Number of lowercase letters: " << lowercaseCount << endl;
    cout << "Number of digits: " << digitCount << endl;

    return 0;
}
