#include <iostream>
#include <string>

using namespace std;

// Function to convert a camel case string to a spaced string with the first word capitalized
string convertCamelCase(const string& camelCase) {
    string spacedString;

    // Process each character in the camel case string
    for (char ch : camelCase) {
        // If the character is uppercase and it's not the first character, add a space
        if (isupper(ch) && !spacedString.empty()) {
            spacedString += ' ';
        }

        // Add the character to the result string
        spacedString += ch;
    }

    return spacedString;
}

int main() {
    string camelCaseString;

    // Input a camel case string from the user
    cout << "Enter a camel case string: ";
    cin >> camelCaseString;

    // Call the function to convert the string
    string spacedString = convertCamelCase(camelCaseString);

    // Display the result
    cout << "Converted string: " << spacedString << endl;

    return 0;
}
