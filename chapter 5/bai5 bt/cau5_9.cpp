#include <iostream>
using namespace std;

int main() {
    int numFloors;
    int totalRooms = 0;
    int totalOccupied = 0;

    // Prompt the user for the number of floors
    cout << "How many floors does the hotel have? ";
    cin >> numFloors;

    // Input validation: Ensure the number of floors is at least 1
    if (numFloors < 1) {
        cout << "Please enter a valid number of floors (at least 1)." << endl;
        return 1; // Exit the program with an error code
    }

    // Iterate once for each floor
    for (int floor = 1; floor <= numFloors; ++floor) {
        int numRooms, numOccupied;

        // Prompt the user for the number of rooms on the current floor
        do {
            cout << "Enter the number of rooms on floor " << floor << " (at least 10): ";
            cin >> numRooms;

            // Input validation: Ensure the number of rooms is at least 10
            if (numRooms < 10) {
                cout << "Please enter a valid number of rooms (at least 10)." << endl;
            }
        } while (numRooms < 10);

        // Prompt the user for the number of occupied rooms on the current floor
        cout << "Enter the number of rooms occupied on floor " << floor << ": ";
        cin >> numOccupied;

        // Input validation: Ensure the number of occupied rooms is non-negative
        if (numOccupied < 0) {
            cout << "Please enter a valid non-negative number of occupied rooms." << endl;
            return 1; // Exit the program with an error code
        }

        totalRooms += numRooms;
        totalOccupied += numOccupied;
    }

    // Calculate the occupancy rate
    double occupancyRate = static_cast<double>(totalOccupied) / totalRooms * 100.0;

    // Display the results
    cout << "Total rooms in the hotel: " << totalRooms << endl;
    cout << "Total rooms occupied: " << totalOccupied << endl;
    cout << "Total rooms unoccupied: " << (totalRooms - totalOccupied) << endl;
    cout << "Occupancy rate: " << occupancyRate << "%" << endl;

    return 0;
}
