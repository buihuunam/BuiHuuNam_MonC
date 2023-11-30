#include <iostream>
#include <string>

using namespace std;

// Function to search and display matching entries in the array
void searchAndDisplay(const string contacts[], int arraySize, const string& searchString) {
    cout << "Matching entries for '" << searchString << "':" << endl;

    // Search for matching entries and display them
    for (int i = 0; i < arraySize; ++i) {
        size_t found = contacts[i].find(searchString);
        if (found != string::npos) {
            cout << contacts[i] << endl;
        }
    }
}

int main() {
    const int arraySize = 10;

    // Array of string objects to store names and phone numbers
    string contacts[arraySize] = {
        "Alejandra Cruz, 555-1223",
        "Joe Looney, 555-0097",
        "Geri Palmer, 555-8787",
        "Li Chen, 555-1212",
        "Holly Gaddis, 555-8878",
        "Sam Wiggins, 555-0998",
        "Bob Kain, 555-8712",
        "Tim Haynes, 555-7676",
        "Warren Gaddis, 555-9037",
        "Jean James, 555-4939"
    };

    // Prompt the user to enter a name or partial name to search for
    cout << "Enter a name or partial name to search for: ";
    string searchString;
    getline(cin, searchString);

    // Call the function to search and display matching entries
    searchAndDisplay(contacts, arraySize, searchString);

    return 0;
}
