#include <iostream>
using namespace std;

int main() {
    // Declare variables
    double wavelength;

    // Get input for the wavelength in meters
    cout << "Enter the wavelength of the electromagnetic wave (in meters): ";
    cin >> wavelength;

    // Determine the type of radiation based on the wavelength
    if (wavelength > 1e-3) {
        cout << "This wave is a Radio Wave." << endl;
    } else if (wavelength <= 1e-3 && wavelength > 1e-6) {
        cout << "This wave is a Microwave." << endl;
    } else if (wavelength <= 1e-6 && wavelength > 7e-7) {
        cout << "This wave is an Infrared Wave." << endl;
    } else if (wavelength <= 7e-7 && wavelength > 4e-7) {
        cout << "This wave is a Visible Light Wave." << endl;
    } else if (wavelength <= 4e-7 && wavelength > 1e-8) {
        cout << "This wave is an Ultraviolet Wave." << endl;
    } else if (wavelength <= 1e-8 && wavelength > 1e-11) {
        cout << "This wave is an X-ray." << endl;
    } else {
        cout << "This wave is a Gamma Ray." << endl;
    }

    return 0;
}