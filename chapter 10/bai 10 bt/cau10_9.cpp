#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to find the most frequent character in a C-string or a string object
char findMostFrequentCharacter(const char* str) {
    unordered_map<char, int> charCount;

    // Count the occurrences of each character
    while (*str != '\0') {
        charCount[*str]++;
        str++;
    }

    // Find the character with the maximum count
    char mostFrequentChar = '\0';
    int maxCount = 0;

    for (const auto& pair : charCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentChar = pair.first;
        }
    }

    return mostFrequentChar;
}

// Overloaded function for std::string
char findMostFrequentCharacter(const string& str) {
    return findMostFrequentCharacter(str.c_str());
}

int main() {
    // Input a string from the user
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString);

    // Call the function to find the most frequent character
    char mostFrequentChar = findMostFrequentCharacter(inputString);

    // Display the result
    cout << "The most frequent character is: " << mostFrequentChar << endl;

    return 0;
}
