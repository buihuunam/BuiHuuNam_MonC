#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Constants for the speed of sound in different gases (in meters per second)
    const double CO2_SPEED = 258.0;
    const double AIR_SPEED = 331.5;
    const double HELIUM_SPEED = 972.0;
    const double HYDROGEN_SPEED = 1270.0;

    // Variables
    char choice;
    double time, distance;

    // Display menu and get user's choice
    cout << "Select a gas for sound wave propagation:" << endl;
    cout << "C - Carbon Dioxide" << endl;
    cout << "A - Air" << endl;
    cout << "H - Helium" << endl;
    cout << "N - Hydrogen" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    // Convert choice to uppercase
    choice = toupper(choice);

    // Input validation: Check that the user has selected a valid option
    if (choice != 'C' && choice != 'A' && choice != 'H' && choice != 'N') {
        cout << "Invalid choice. Please select C, A, H, or N." << endl;
        return 1;  // Exit with an error code
    }

    // Get the time from the user (must be between 0 and 30 seconds)
    cout << "Enter the time it took for the sound wave to travel (in seconds): ";
    cin >> time;

    if (time < 0 || time > 30) {
        cout << "Invalid time. Please enter a time between 0 and 30 seconds." << endl;
        return 1;  // Exit with an error code
    }

    // Calculate the distance based on the selected gas and time
    switch (choice) {
        case 'C':
            distance = CO2_SPEED * time;
            break;
        case 'A':
            distance = AIR_SPEED * time;
            break;
        case 'H':
            distance = HELIUM_SPEED * time;
            break;
        case 'N':
            distance = HYDROGEN_SPEED * time;
            break;
    }

    // Display the result rounded to two decimal places
    cout << fixed << setprecision(2);
    cout << "The source of the sound was " << distance << " meters away from the detection location." << endl;

    return 0;
}
