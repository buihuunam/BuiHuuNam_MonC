#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int MAX_NAME_LENGTH = 100;

    char firstName[MAX_NAME_LENGTH];
    char middleName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char fullName[MAX_NAME_LENGTH * 3 + 4]; // Maximum length for full name

    // Input user's first, middle, and last names
    cout << "Enter your first name: ";
    cin.getline(firstName, MAX_NAME_LENGTH);

    cout << "Enter your middle name: ";
    cin.getline(middleName, MAX_NAME_LENGTH);

    cout << "Enter your last name: ";
    cin.getline(lastName, MAX_NAME_LENGTH);

    // Construct the full name in the specified format
    strcpy(fullName, lastName);
    strcat(fullName, ", ");
    strcat(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName, middleName);

    // Display the full name
    cout << "Full Name: " << fullName << endl;

    return 0;
}
