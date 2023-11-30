#include <iostream>
#include <string>
using namespace std;

int main() {
    // Constants for package prices and included minutes
    const double PACKAGE_A_PRICE = 39.99;
    const double PACKAGE_B_PRICE = 59.99;
    const double PACKAGE_C_PRICE = 69.99;
    const int PACKAGE_A_MINUTES = 450;
    const int PACKAGE_B_MINUTES = 900;

    // Constants for the number of minutes in each month
    const int JAN_MINUTES = 744;
    const int FEB_MINUTES = 672;
    const int MAR_MINUTES = 744;
    const int APR_MINUTES = 720;
    const int MAY_MINUTES = 744;
    const int JUN_MINUTES = 720;
    const int JUL_MINUTES = 744;
    const int AUG_MINUTES = 744;
    const int SEP_MINUTES = 720;
    const int OCT_MINUTES = 744;
    const int NOV_MINUTES = 720;
    const int DEC_MINUTES = 744;

    const char A;
    const char B;
    const char C;

    // Variables
    char package;
    int minutesUsed;
    double totalAmountDue;
    string monthName;

    // Display menu and get user's package choice
    cout << "Select your subscription package (A, B, or C): ";
    cin >> package;
    package = toupper(package);  // Convert to uppercase for case insensitivity

    // Input validation: Check that the user has selected a valid package
    if (package != 'A' && package != 'B' && package != 'C') {
        cout << "Invalid package selection. Please choose A, B, or C." << endl;
        return 1;  // Exit with an error code
    }

    // Get the month name from the user
    cout << "Enter the name of the month (e.g., January, February, etc.): ";
    cin.ignore();  // Clear the newline character from the previous input
    getline(cin, monthName);

    // Convert the month name to uppercase for case insensitivity
    for (char &c : monthName) {
        c = toupper(c);
    }

    // Get the number of minutes used
    cout << "Enter the number of minutes used: ";
    cin >> minutesUsed;

    // Input validation: Check that the number of minutes is not more than the maximum for the entire month
    int maxMinutes;
    if (monthName == "JANUARY") {
        maxMinutes = JAN_MINUTES;
    } else if (monthName == "FEBRUARY") {
        maxMinutes = FEB_MINUTES;
    } else if (monthName == "MARCH") {
        maxMinutes = MAR_MINUTES;
    } else if (monthName == "APRIL") {
        maxMinutes = APR_MINUTES;
    } else if (monthName == "MAY") {
        maxMinutes = MAY_MINUTES;
    } else if (monthName == "JUNE") {
        maxMinutes = JUN_MINUTES;
    } else if (monthName == "JULY") {
        maxMinutes = JUL_MINUTES;
    } else if (monthName == "AUGUST") {
        maxMinutes = AUG_MINUTES;
    } else if (monthName == "SEPTEMBER") {
        maxMinutes = SEP_MINUTES;
    } else if (monthName == "OCTOBER") {
        maxMinutes = OCT_MINUTES;
    } else if (monthName == "NOVEMBER") {
        maxMinutes = NOV_MINUTES;
    } else if (monthName == "DECEMBER") {
        maxMinutes = DEC_MINUTES;
    } else {
        cout << "Invalid month name. Please enter a valid month name." << endl;
        return 1;  // Exit with an error code
    }

    if (minutesUsed > maxMinutes) {
        cout << "Invalid number of minutes. The maximum for " << monthName << " is " << maxMinutes << " minutes." << endl;
        return 1;  // Exit with an error code
    }

    // Calculate the total amount due based on the selected package and minutes used
    switch (package) {
        case 'A':
            if (minutesUsed <= PACKAGE_A_MINUTES) {
                totalAmountDue = PACKAGE_A_PRICE;
            } else {
                totalAmountDue = PACKAGE_A_PRICE + (minutesUsed - PACKAGE_A_MINUTES) * 0.45;
            }

            // Calculate savings for Package A customers if they purchased Package B or C
            double savingsB_A = PACKAGE_B_PRICE - totalAmountDue;
            double savingsC_A = PACKAGE_C_PRICE - totalAmountDue;

            // Display savings if they exist
            if (savingsB_A > 0) {
                cout << "Savings if you purchased Package B: $" << savingsB_A << endl;
            }
            if (savingsC_A > 0) {
                cout << "Savings if you purchased Package C: $" << savingsC_A << endl;
            }
            break;
        case 'B':
            if (minutesUsed <= PACKAGE_B_MINUTES) {
                totalAmountDue = PACKAGE_B_PRICE;
            } else {
                totalAmountDue = PACKAGE_B_PRICE + (minutesUsed - PACKAGE_B_MINUTES) * 0.40;
            }

            // Calculate savings for Package B customers if they purchased Package C
            double savingsC_B = PACKAGE_C_PRICE - totalAmountDue;

            // Display savings if they exist
            if (savingsC_B > 0) {
                cout << "Savings if you purchased Package C: $" << savingsC_B << endl;
            }
            break;
        case 'C':
            totalAmountDue = PACKAGE_C_PRICE;
            break;
        default:
            break;
    }

    // Display the total amount due
    cout << "Total amount due: $" << totalAmountDue << endl;

    return 0;
}