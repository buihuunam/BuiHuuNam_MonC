#include <iostream>

using namespace std;

class Shape {
public:
    // Hàm ảo để tính diện tích
    virtual void calculateArea() const {
        cout << "Area of the base class Shape" << endl;
    }
};

class Circle : public Shape {
public:
    // Override hàm ảo để tính diện tích của hình tròn
    void calculateArea() const override {
        cout << "Area of the Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    // Override hàm ảo để tính diện tích của hình chữ nhật
    void calculateArea() const override {
        cout << "Area of the Rectangle" << endl;
    }
};

int main() {
    // Tạo đối tượng Circle và gọi hàm calculateArea()
    Circle circle;
    circle.calculateArea();

    // Tạo đối tượng Rectangle và gọi hàm calculateArea()
    Rectangle rectangle;
    rectangle.calculateArea();

    // Tạo đối tượng Shape (con trỏ) và gọi hàm calculateArea() (tùy thuộc vào kiểu thực tế)
    Shape* shapePtr;
    shapePtr = &circle;
    shapePtr->calculateArea();

    shapePtr = &rectangle;
    shapePtr->calculateArea();

    return 0;
}
