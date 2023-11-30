// This program uses the Rectangle class's constructor.
#include <iostream>
#include "Rectangle.h" // Needed for Rectangle class
using namespace std;
class Rectangle
    {
        private:
        double width;
        double length;
        public:
        void setWidth(double);
        void setLength(double);
        double getWidth() const;
        double getLength() const;
        double getArea() const;
        };

//**************************************************
// setWidth assigns a value to the width member. *
//**************************************************

void Rectangle::setWidth(double w)
    {
        width = w;
        }

//***************************************************
// setLength assigns a value to the length member. *
//***************************************************

void Rectangle::setLength(double len)
    {
        length = len;
        }

//***************************************************
// getWidth returns the value in the width member. *
//***************************************************

double Rectangle::getWidth() const
    {
        return width;
        }

//****************************************************
// getLength returns the value in the length member. *
//****************************************************

double Rectangle::getLength() const
    {
        return length;
        }

//******************************************************
// getArea returns the product of width times length. *
//******************************************************

double Rectangle::getArea() const
    {
        return width * length;
        }
int main()
    {
        Rectangle box; // Define an instance of the Rectangle class

        // Display the rectangle's data.
        cout << "Here is the rectangle's data:\n";
        cout << "Width: " << box.getWidth() << endl;
        cout << "Length: " << box.getLength() << endl;
        cout << "Area: " << box.getArea() << endl;
        return 0;
        }