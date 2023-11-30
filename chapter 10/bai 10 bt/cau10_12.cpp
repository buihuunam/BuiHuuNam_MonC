#include <iostream>
#include <cctype> // For isdigit, islower, isupper functions

using namespace std;

bool isValidPassword(const string& password) {
    // Check if the password is at least six characters long
    if (password.length() < 6) {
        cout << "Password should be at least six characters long." << endl;
        return false;
    }

    // Check if the password contains at least one uppercase and one lowercase letter
    bool hasUppercase = false;
    bool hasLowercase = false;

    for (char ch : password) {
        if (isupper(ch)) {
            hasUppercase = true;
        } else if (islower(ch)) {
            hasLowercase = true;
        }
    }

    if (!hasUppercase || !hasLowercase) {
        cout << "Password should contain at least one uppercase and one lowercase letter." << endl;
        return false;
    }

    // Check if the password has at least one digit
    bool hasDigit = false;

    for (char ch : password) {
        if (isdigit(ch)) {
            hasDigit = true;
            break;
        }
    }

    if (!hasDigit) {
        cout << "Password should have at least one digit." << endl;
        return false;
    }

    // If all criteria are met, the password is valid
    return true;
}

int main() {
    string password;

    // Input a password from the user
    cout << "Enter your password: ";
    getline(cin, password);

    // Check if the password is valid
    if (isValidPassword(password)) {
        cout << "Password is valid. Welcome!" << endl;
    } else {
        cout << "Password is not valid. Please try again." << endl;
    }

    return 0;
}
