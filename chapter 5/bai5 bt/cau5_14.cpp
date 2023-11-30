#include <iostream>
#include <string>
using namespace std;

int main() {
    int numStudents;

    // Prompt the user for the number of students
    cout << "Enter the number of students in the class (1-25): ";
    cin >> numStudents;

    // Input validation: Ensure the number of students is within the specified range
    if (numStudents < 1 || numStudents > 25) {
        cout << "Please enter a valid number of students within the range of 1 to 25." << endl;
        return 1; // Exit the program with an error code
    }

    cin.ignore(); // Clear the newline character from the input buffer

    string firstName, firstInLine, lastInLine;

    // Loop to read the names of students
    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter the name of student " << (i + 1) << ": ";
        getline(cin, firstName);

        if (i == 0) {
            firstInLine = lastInLine = firstName; // Initialize first and last names
        } else {
            // Check if the current name should be at the front or end of the line
            if (firstName < firstInLine) {
                firstInLine = firstName;
            }
            if (firstName > lastInLine) {
                lastInLine = firstName;
            }
        }
    }

    // Display the student at the front and end of the line
    cout << "Student at the front of the line: " << firstInLine << endl;
    cout << "Student at the end of the line: " << lastInLine << endl;

    return 0;
}
