#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("People.txt");

    if (!inputFile) {
        cout << "Error opening the input file." << endl;
        return 1; // Exit with an error code
    }

    cout << "PRAIRIEVILLE POPULATION GROWTH" << endl;
    cout << "(each * represents 1,000 people)" << endl;

    int year = 1900;
    string line;
    
    while (getline(inputFile, line)) {
        int population = stoi(line); // Convert the line to an integer
        int numAsterisks = population / 1000; // Calculate the number of asterisks

        cout << year << " ";
        
        for (int i = 0; i < numAsterisks; ++i) {
            cout << "*";
        }

        cout << endl;
        year += 20;
    }

    inputFile.close();

    return 0;
}
