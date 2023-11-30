#include <iostream>
using namespace std;

int main() {
    int number;
    int largest = INT_MIN; // Initialize to the smallest possible integer
    int smallest = INT_MAX; // Initialize to the largest possible integer

    cout << "Enter a series of integers (enter -99 to end):" << endl;

    while (true) {
        cout << "Enter an integer: ";
        cin >> number;

        if (number == -99) {
            break; // Exit the loop when -99 is entered
        }

        // Update the largest and smallest numbers
        if (number > largest) {
            largest = number;
        }
        if (number < smallest) {
            smallest = number;
        }
    }

    if (largest == INT_MIN && smallest == INT_MAX) {
        cout << "No valid numbers were entered." << endl;
    } else {
        cout << "Largest number entered: " << largest << endl;
        cout << "Smallest number entered: " << smallest << endl;
    }

    return 0;
}
