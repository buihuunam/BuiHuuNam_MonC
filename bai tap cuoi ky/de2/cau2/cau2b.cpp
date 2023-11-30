#include <iostream>

using namespace std;

// Lớp trừu tượng
class Shape {
public:
    // Hàm thuần ảo để tính diện tích
    virtual void calculateArea() const = 0;

    // Hàm thông thường
    void displayMessage() const {
        cout << "This is a Shape." << endl;
    }
};

// Lớp dẫn xuất từ lớp trừu tượng
class Circle : public Shape {
public:
    // Override hàm thuần ảo để tính diện tích của hình tròn
    void calculateArea() const override {
        cout << "Area of the Circle" << endl;
    }
};

// Lớp dẫn xuất từ lớp trừu tượng
class Rectangle : public Shape {
public:
    // Override hàm thuần ảo để tính diện tích của hình chữ nhật
    void calculateArea() const override {
        cout << "Area of the Rectangle" << endl;
    }
};

int main() {
    Circle circle;
    Rectangle rectangle;

    // Gọi hàm thông thường của lớp cơ sở
    circle.displayMessage();
    rectangle.displayMessage();

    // Gọi hàm thuần ảo của lớp dẫn xuất
    circle.calculateArea();
    rectangle.calculateArea();

    return 0;
}
