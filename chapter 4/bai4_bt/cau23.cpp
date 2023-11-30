#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int choice;

    while (true) {
        // Display the menu
        cout << "Geometry Calculator" << endl;
        cout << "1. Calculate the Area of a Circle" << endl;
        cout << "2. Calculate the Area of a Rectangle" << endl;
        cout << "3. Calculate the Area of a Triangle" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";

        cin >> choice;

        // Handle the user's choice
        switch (choice) {
            case 1: {
                // Calculate the area of a circle
                double radius;
                cout << "Enter the radius of the circle: ";
                cin >> radius;

                // Input validation: Check for negative radius
                if (radius < 0) {
                    cout << "Radius cannot be negative. Please enter a non-negative radius." << endl;
                    break;
                }

                double area = M_PI * pow(radius, 2);
                cout << "The area of the circle is: " << area << endl;
                break;
            }
            case 2: {
                // Calculate the area of a rectangle
                double length, width;
                cout << "Enter the length of the rectangle: ";
                cin >> length;
                cout << "Enter the width of the rectangle: ";
                cin >> width;

                // Input validation: Check for negative length or width
                if (length < 0 || width < 0) {
                    cout << "Length and width cannot be negative. Please enter non-negative values." << endl;
                    break;
                }

                double area = length * width;
                cout << "The area of the rectangle is: " << area << endl;
                break;
            }
            case 3: {
                // Calculate the area of a triangle
                double base, height;
                cout << "Enter the length of the triangle's base: ";
                cin >> base;
                cout << "Enter the height of the triangle: ";
                cin >> height;

                // Input validation: Check for negative base or height
                if (base < 0 || height < 0) {
                    cout << "Base and height cannot be negative. Please enter non-negative values." << endl;
                    break;
                }

                double area = 0.5 * base * height;
                cout << "The area of the triangle is: " << area << endl;
                break;
            }
            case 4:
                // Quit the program
                cout << "Exiting the program." << endl;
                return 0;
            default:
                // Input validation: Handle invalid choices
                cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
                break;
        }
    }

    return 0;
}
