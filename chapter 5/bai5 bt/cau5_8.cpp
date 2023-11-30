#include <iostream>
using namespace std;

int main() {
    //xuat ra cac lua chon
    char choice;
    do {
        cout << "Menu:" << endl;
        cout << "A) Addition" << endl;
        cout << "S) Subtraction" << endl;
        cout << "M) Multiplication" << endl;
        cout << "D) Division" << endl;
        cout << "Q) Quit" << endl;
        cout << "Choose an operation (A/S/M/D/Q): ";
        cin >> choice;
        //yeu cau nguoi dung chon 1 trong cac muc tren
        switch (choice) {
            case 'A':
            case 'a': {
                double num1, num2;
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 + num2 << endl;
                break;
            }
            case 'S':
            case 's': {
                double num1, num2;
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 - num2 << endl;
                break;
            }
            case 'M':
            case 'm': {
                double num1, num2;
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 * num2 << endl;
                break;
            }
            case 'D':
            case 'd': {
                double num1, num2;
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                if (num2 != 0) {
                    cout << "Result: " << num1 / num2 << endl;
                } else {
                    cout << "Division by zero is not allowed." << endl;
                }
                break;
            }
            case 'Q':
            case 'q':
                cout << "Quitting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please choose a valid operation." << endl;
                break;
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}
