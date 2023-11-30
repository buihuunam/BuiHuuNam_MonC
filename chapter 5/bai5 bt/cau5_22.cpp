#include <iostream>
using namespace std;
int main() {
    int sideLength;

    // Ask the user for a positive integer
    do {
        cout << "Enter a positive integer (1-15): ";
        cin >> sideLength;
    } while (sideLength < 1 || sideLength > 15);

    // Display the square
    for (int row = 0; row < sideLength; ++row) {
        for (int col = 0; col < sideLength; ++col) {
            cout << 'X';
        }
        cout << endl;
    }

    return 0;
}
