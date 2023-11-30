#include <iostream>
#include <map>
#include <sstream>

using namespace std;

// Function to convert a character to Morse code
string charToMorse(char character) {
    // Define Morse code mapping
    map<char, string> morseCode = {
        {' ', " "}, {',', "--..--"}, {'.', ".-.-.-"},
        {'?', "..--.."}, {'0', "-----"}, {'1', ".----"},
        {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
        {'5', "....."}, {'6', "-...."}, {'7', "--..."},
        {'8', "---.."}, {'9', "----."}, {'A', ".-"},
        {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
        {'E', "."}, {'F', "..-."}, {'G', "--."},
        {'H', "...."}, {'I', ".."}, {'J', ".---"},
        {'K', "-.-"}, {'L', ".-.."}, {'M', "--"},
        {'N', "-."}, {'O', "---"}, {'P', ".--."},
        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."},
        {'T', "-"}, {'U', "..-"}, {'V', "...-"},
        {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
        {'Z', "--.."}
    };

    // Convert the character to uppercase
    character = toupper(character);

    // Return Morse code for the character, or an empty string if not found
    return morseCode.find(character) != morseCode.end() ? morseCode[character] : "";
}

// Function to convert a string to Morse code
string stringToMorse(const string& inputString) {
    stringstream morseStream;

    // Process each character in the input string
    for (char ch : inputString) {
        // Convert the character to Morse code and append to the result
        morseStream << charToMorse(ch) << " ";
    }

    return morseStream.str();
}

int main() {
    string inputString;

    // Input a string from the user
    cout << "Enter a string: ";
    getline(cin, inputString);

    // Call the function to convert the string to Morse code
    string morseCode = stringToMorse(inputString);

    // Display the result
    cout << "Morse Code: " << morseCode << endl;

    return 0;
}
