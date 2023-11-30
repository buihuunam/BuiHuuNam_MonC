#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BigInteger {
private:
    string value;

public:
    // Constructors
    BigInteger() : value("0") {}
    BigInteger(const string& str) : value(removeLeadingZeros(str)) {}

    // Overloaded input operator
    friend istream& operator>>(istream& in, BigInteger& num) {
        cout << "Input an integer = ";
        in >> num.value;
        num.value = removeLeadingZeros(num.value);
        return in;
    }

    // Overloaded equality operator
    friend bool operator==(const BigInteger& num1, const BigInteger& num2) {
        return num1.value == num2.value;
    }

private:
    // Helper function to remove leading zeros from the string
    static string removeLeadingZeros(const string& str) {
        auto it = find_if_not(str.begin(), str.end(), [](char c) { return c == '0' || c == ' '; });
        return (it == str.end()) ? "0" : string(it, str.end());
    }
};

int main() {
    BigInteger n1(" 1234567891011 "); // Initialization from string.
    BigInteger n2; // Default initialization = 0.
    cin >> n2; // Input value from the console.

    if (n1 == n2)
        cout << "Equal.\n";
    else
        cout << "Not equal.\n";

    return 0;
}
