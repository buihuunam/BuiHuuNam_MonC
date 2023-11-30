#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define a structure to store vault details
struct Vault {
    string date;
    double height;
};

// Function to compare Vaults based on height for sorting
bool compareVaults(const Vault& a, const Vault& b) {
    return a.height > b.height;
}

int main() {
    string vaulterName;
    vector<Vault> vaults;

    cout << "Enter the name of the pole vaulter: ";
    getline(cin, vaulterName);

    for (int i = 0; i < 3; i++) {
        Vault vault;
        cout << "Enter the date of vault " << i + 1 << " (MM/DD/YYYY): ";
        getline(cin, vault.date);
        cout << "Enter the height (in meters) of vault " << i + 1 << ": ";
        cin >> vault.height;
        cin.ignore();  // Consume the newline character

        vaults.push_back(vault);
    }

    // Sort the vaults in descending order of height
    sort(vaults.begin(), vaults.end(), compareVaults);

    // Print the sorted vaults
    cout << "\n" << vaulterName << "'s Best Pole Vault Performances:" << endl;
    for (int i = 0; i < vaults.size(); i++) {
        cout << i + 1 << ". Date: " << vaults[i].date << ", Height: " << vaults[i].height << " meters" << endl;
    }

    return 0;
}
