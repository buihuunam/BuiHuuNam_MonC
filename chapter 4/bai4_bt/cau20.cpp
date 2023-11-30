#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Constants for the speed of sound in different mediums (in feet per second)
    const double AIR_SPEED = 1100.0;
    const double WATER_SPEED = 4900.0;
    const double STEEL_SPEED = 16400.0;

    // Variables
    char choice;
    double distance, time;

    // Display menu and get user's choice
    cout << "Select a medium for sound wave propagation:" << endl;
    cout << "A - Air" << endl;
    cout << "W - Water" << endl;
    cout << "S - Steel" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    // Convert choice to uppercase
    choice = toupper(choice);

    // Input validation: Check that the user has selected a valid option
    if (choice != 'A' && choice != 'W' && choice != 'S') {
        cout << "Invalid choice. Please select A, W, or S." << endl;
        return 1;  // Exit with an error code
    }

    // Get the distance from the user (must be non-negative)
    cout << "Enter the distance the sound wave will travel (in feet): ";
    cin >> distance;

    if (distance < 0) {
        cout << "Distance cannot be negative. Please enter a non-negative distance." << endl;
        return 1;  // Exit with an error code
    }

    // Calculate the time it takes for the sound wave to travel the given distance
    switch (choice) {
        case 'A':
            time = distance / AIR_SPEED;
            break;
        case 'W':
            time = distance / WATER_SPEED;
            break;
        case 'S':
            time = distance / STEEL_SPEED;
            break;
    }

    // Display the result rounded to four decimal places
    cout << fixed << setprecision(4);
    cout << "It will take " << time << " seconds for the sound wave to travel " << distance << " feet in ";
    
    // Display the selected medium
    switch (choice) {
        case 'A':
            cout << "air." << endl;
            break;
        case 'W':
            cout << "water." << endl;
            break;
        case 'S':
            cout << "steel." << endl;
            break;
    }

    return 0;
}
