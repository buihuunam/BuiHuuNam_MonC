#include <iostream>
using namespace std;

int main() {
    // Constants for rate per minute during different time periods
    const double RATE_OFF_PEAK = 0.05;
    const double RATE_DAYTIME = 0.45;
    const double RATE_EVENING = 0.20;

    // Variables
    double startTime, minutes, totalCharge;

    // Get user input for the starting time (in HH.MM format)
    cout << "Enter the starting time of the call (HH.MM): ";
    cin >> startTime;

    // Input validation: Check if the entered time is valid
    if (startTime < 0 || startTime >= 24 || static_cast<int>(startTime * 100) % 100 >= 60) {
        cout << "Invalid time format. Please enter a valid time." << endl;
        return 1;  // Exit with an error code
    }

    // Get user input for the number of minutes
    cout << "Enter the number of minutes for the call: ";
    cin >> minutes;

    // Calculate the total charge based on the time of day
    if (startTime >= 0 && startTime < 7) {
        totalCharge = minutes * RATE_OFF_PEAK;
    } else if (startTime >= 7 && startTime < 19) {
        totalCharge = minutes * RATE_DAYTIME;
    } else {
        totalCharge = minutes * RATE_EVENING;
    }

    // Display the calculated charge
    cout << "Total charge for the call: $" << totalCharge << endl;

    return 0;
}
