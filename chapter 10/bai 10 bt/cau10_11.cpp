#include <iostream>
#include <cstring>

using namespace std;

// Function to convert a C-string to uppercase
void upper(char* str) {
    while (*str != '\0') {
        *str = toupper(*str);
        str++;
    }
}

// Function to convert a C-string to lowercase
void lower(char* str) {
    while (*str != '\0') {
        *str = tolower(*str);
        str++;
    }
}

// Function to reverse the case of characters in a C-string
void reverse(char* str) {
    while (*str != '\0') {
        if (isupper(*str)) {
            *str = tolower(*str);
        } else if (islower(*str)) {
            *str = toupper(*str);
        }

        str++;
    }
}

int main() {
    const int MAX_SIZE = 100;
    char inputString[MAX_SIZE];

    // Input a string from the user
    cout << "Enter a string: ";
    cin.getline(inputString, MAX_SIZE);

    // Call the functions in the specified order: reverse, lower, and upper
    reverse(inputString);
    cout << "After reversing the case: " << inputString << endl;

    lower(inputString);
    cout << "After converting to lowercase: " << inputString << endl;

    upper(inputString);
    cout << "After converting to uppercase: " << inputString << endl;

    return 0;
}
