#include <iostream>
using namespace std;

int main() {
    int month, day, year;

    // Ask the user to enter the month, day, and two-digit year
    cout << "Enter a month (numeric form): ";
    cin >> month;

    cout << "Enter a day: ";
    cin >> day;

    cout << "Enter a two-digit year: ";
    cin >> year;

    // Check if the date is "magic" (month times day equals year)
    if (month * day == year) {
        cout << "The date is magic!" << endl;
    } else {
        cout << "The date is not magic." << endl;
    }

    return 0;
}
