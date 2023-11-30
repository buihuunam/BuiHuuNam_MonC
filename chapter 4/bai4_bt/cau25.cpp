#include <iostream>
using namespace std;

int main() {
    // Constants for package prices and included minutes
    const double PACKAGE_A_PRICE = 39.99;
    const double PACKAGE_B_PRICE = 59.99;
    const double PACKAGE_C_PRICE = 69.99;
    const int PACKAGE_A_MINUTES = 450;
    const int PACKAGE_B_MINUTES = 900;

    // Variables
    char package;
    int minutesUsed;
    double totalAmountDue;

    // Display menu and get user's package choice
    cout << "Select your subscription package (A, B, or C): ";
    cin >> package;
    package = toupper(package);  // Convert to uppercase for case insensitivity

    // Input validation: Check that the user has selected a valid package
    if (package != 'A' && package != 'B' && package != 'C') {
        cout << "Invalid package selection. Please choose A, B, or C." << endl;
        return 1;  // Exit with an error code
    }

    // Get the number of minutes used
    cout << "Enter the number of minutes used: ";
    cin >> minutesUsed;

    // Calculate the total amount due based on the selected package and minutes used
    switch (package) {
        case 'A':
            if (minutesUsed <= PACKAGE_A_MINUTES) {
                totalAmountDue = PACKAGE_A_PRICE;
            } else {
                totalAmountDue = PACKAGE_A_PRICE + (minutesUsed - PACKAGE_A_MINUTES) * 0.45;
            }
            break;
        case 'B':
            if (minutesUsed <= PACKAGE_B_MINUTES) {
                totalAmountDue = PACKAGE_B_PRICE;
            } else {
                totalAmountDue = PACKAGE_B_PRICE + (minutesUsed - PACKAGE_B_MINUTES) * 0.40;
            }
            break;
        case 'C':
            totalAmountDue = PACKAGE_C_PRICE;
            break;
    }

    // Display the total amount due
    cout << "Total amount due: $" << totalAmountDue << endl;

    return 0;
}
