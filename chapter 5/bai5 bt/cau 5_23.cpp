#include <iostream>
using namespace std;
int main() {
    int rows = 10; // Number of rows

    // Pattern A
    cout << "Pattern A" << endl;
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << "+";
        }
        cout << endl;
    }

    // Pattern B
    cout << "Pattern B" << endl;
    for (int i = 1; i <= rows; ++i) {
        // Print spaces
        for (int j = 1; j <= rows - i; ++j) {
            cout << " ";
        }
        // Print '+'
        for (int j = 1; j <= i; ++j) {
            cout << "+";
        }
        cout << endl;
    }

    return 0;
}
