#include <iostream>
using namespace std;
bool isLeapYear(int year) {
    if ((year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) {
        return true;
    } else {
        return false;
    }
}

int getNumberOfDays(int month, int year) {
    // Define the number of days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust February for leap years
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    return daysInMonth[month - 1];
}

int main() {
    int month, year;

    // Input month and year
    cout << "Enter a month (1-12): ";
    cin >> month;
    cout << "Enter a year: ";
    cin >> year;

    // Validate the input
    if (month < 1 || month > 12 || year < 1) {
        cout << "Invalid input. Month should be between 1 and 12, and year should be a positive integer." << std::endl;
    } else {
        // Get the number of days and display it
        int numDays = getNumberOfDays(month, year);
        cout << "Number of days in the selected month: " << numDays << std::endl;
    }

    return 0;
}
