#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Function to convert mm/dd/yyyy format to "Month dd, yyyy" format
string formatDate(const string& inputDate) {
    // Create string stream to parse date components
    stringstream ss(inputDate);

    // Variables to store date components
    int month, day, year;

    // Extract month, day, and year from the input string
    char delimiter;
    ss >> month >> delimiter >> day >> delimiter >> year;

    // Array of month names
    string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Validate month
    if (month < 1 || month > 12) {
        cout << "Invalid month. Please enter a valid date." << endl;
        return "";
    }

    // Validate day
    if (day < 1 || day > 31) {
        cout << "Invalid day. Please enter a valid date." << endl;
        return "";
    }

    // Validate year
    if (year < 0) {
        cout << "Invalid year. Please enter a valid date." << endl;
        return "";
    }

    // Format the date
    return months[month - 1] + " " + to_string(day) + ", " + to_string(year);
}

int main() {
    string inputDate;

    // Input a date from the user
    cout << "Enter a date in mm/dd/yyyy format: ";
    cin >> inputDate;

    // Call the function to format the date
    string formattedDate = formatDate(inputDate);

    // Display the result
    if (!formattedDate.empty()) {
        cout << "Formatted date: " << formattedDate << endl;
    }

    return 0;
}
