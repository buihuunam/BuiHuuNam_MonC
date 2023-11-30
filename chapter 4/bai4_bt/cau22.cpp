#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to represent substance data
struct Substance {
    string name;
    int freezePoint;
    int boilPoint;
};

int main() {
    // Define substance data
    vector<Substance> substances = {
        {"Ethyl alcohol", -173, 172},
        {"Mercury", -38, 676},
        {"Oxygen", -362, -306},
        {"Water", 32, 212}
    };

    // Get user input for the temperature
    int temperature;
    cout << "Enter a temperature in Fahrenheit: ";
    cin >> temperature;

    // Initialize vectors to store substances that will freeze and boil at the given temperature
    vector<string> substancesToFreeze;
    vector<string> substancesToBoil;

    // Check which substances will freeze and/or boil at the given temperature
    for (const Substance& substance : substances) {
        if (temperature <= substance.freezePoint) {
            substancesToFreeze.push_back(substance.name);
        }
        if (temperature >= substance.boilPoint) {
            substancesToBoil.push_back(substance.name);
        }
    }

    // Display the substances that will freeze and/or boil at the given temperature
    cout << "Substances that will ";
    if (!substancesToFreeze.empty()) {
        cout << "freeze: ";
        for (size_t i = 0; i < substancesToFreeze.size(); ++i) {
            cout << substancesToFreeze[i];
            if (i < substancesToFreeze.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    } else {
        cout << "not freeze at this temperature." << endl;
    }

    cout << "Substances that will ";
    if (!substancesToBoil.empty()) {
        cout << "boil: ";
        for (size_t i = 0; i < substancesToBoil.size(); ++i) {
            cout << substancesToBoil[i];
            if (i < substancesToBoil.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    } else {
        cout << "not boil at this temperature." << endl;
    }

    return 0;
}
