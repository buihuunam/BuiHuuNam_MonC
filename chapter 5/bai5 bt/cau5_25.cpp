#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ifstream inputFile("LineUp.txt"); // Open the input file
    vector<string> names; // Vector to store the names

    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    string name;

    // Read names from the file until there is no more data
    while (getline(inputFile, name)) {
        names.push_back(name);
    }

    inputFile.close(); // Close the input file

    // Display the names
    cout << "List of students:" << endl;
    for (const string& student : names) {
        cout << student << endl;
    }

    return 0;
}
