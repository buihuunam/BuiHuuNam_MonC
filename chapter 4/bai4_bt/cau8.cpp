#include <iostream>
#include <string>
using namespace std;

int main() {
    string color1, color2;

    // Ask the user to enter two primary colors
    cout << "Enter the first primary color (red, blue, or yellow): ";
    cin >> color1;

    cout << "Enter the second primary color (red, blue, or yellow): ";
    cin >> color2;

    // Check if the entered colors are valid primary colors
    if (color1 == "red" || color1 == "blue" || color1 == "yellow") {
        if (color2 == "red" || color2 == "blue" || color2 == "yellow") {
            // Determine and display the resulting secondary color
            if ((color1 == "red" && color2 == "blue") || (color1 == "blue" && color2 == "red")) {
                cout << "Mixing " << color1 << " and " << color2 << " produces purple." << endl;
            } else if ((color1 == "red" && color2 == "yellow") || (color1 == "yellow" && color2 == "red")) {
                cout << "Mixing " << color1 << " and " << color2 << " produces orange." << endl;
            } else if ((color1 == "blue" && color2 == "yellow") || (color1 == "yellow" && color2 == "blue")) {
                cout << "Mixing " << color1 << " and " << color2 << " produces green." << endl;
            } else {
                cout << "Invalid combination of primary colors." << endl;
            }
        } else {
            cout << "Invalid second primary color." << endl;
        }
    } else {
        cout << "Invalid first primary color." << endl;
    }

    return 0;
}
