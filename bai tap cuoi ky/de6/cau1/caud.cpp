#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
using namespace std;

const double PI = 3.1415928;

// Lớp cơ sở Shape định nghĩa các phương thức ảo và thuần ảo
class Shape {
public:
    Shape() {
        cerr << "construct Shape" << endl;
    }

    virtual string Description() {
        stringstream ss;
        ss << "Shape(area=" << this->Area() << ")";
        return ss.str();
    }

    virtual float Area() = 0; // Phương thức ảo thuần ảo
    virtual void Scale(float scaleFactor) = 0; // Phương thức ảo thuần ảo

    const type_info& InterfaceType() {
        return typeid(Shape);
    }

    const type_info& ImplementationType() {
        return typeid(*this);
    }

    virtual ~Shape() {
        cerr << "destruct Shape" << endl;
    }
};

// Lớp Circle kế thừa từ Shape và cài đặt các phương thức ảo
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : Shape(), radius(r) {
        cerr << "construct Circle" << endl;
    }

    string Description() override {
        stringstream ss;
        ss << "Circle(r=" << this->radius << ")";
        return ss.str();
    }

    float Area() override {
        return PI * radius * radius;
    }

    void Scale(float scaleFactor) override {
        this->radius *= scaleFactor;
    }

    const type_info& InterfaceType() override {
        return typeid(Circle);
    }

    ~Circle() {
        cerr << "destruct Circle" << endl;
    }
};

// Lớp Ellipse kế thừa từ Shape và cài đặt các phương thức ảo
class Ellipse : public Shape {
private:
    float majorR, minorR;

public:
    Ellipse(float a, float b) : Shape(), majorR(a), minorR(b) {
        cerr << "construct Ellipse" << endl;
    }

    string Description() override {
        stringstream ss;
        ss << "Ellipse(a=" << this->majorR << ", b=" << this->minorR << ")";
        return ss.str();
    }

    float Area() override {
        return PI * majorR * minorR;
    }

    void Scale(float scaleFactor) override {
        this->majorR *= scaleFactor;
        this->minorR *= scaleFactor;
    }

    void Scale(float sa, float sb) override {
        this->majorR *= sa;
        this->minorR *= sb;
    }

    const type_info& InterfaceType() override {
        return typeid(Ellipse);
    }

    ~Ellipse() {
        cerr << "destruct Ellipse" << endl;
    }
};

int main() {
    // Tạo đối tượng Ellipse và trỏ đến nó bằng con trỏ Shape
    Ellipse ellipse(2.0/3, 6);
    Shape *shape = &ellipse;

    // Gọi phương thức Scale thông qua con trỏ Shape sử dụng dynamic_cast
    dynamic_cast<Ellipse*>(shape)->Scale(3, 1.0/3);

    // Xuất thông tin của đối tượng Ellipse và con trỏ Shape
    cout << "ellipse: " << endl;
    cout << ellipse.Description() << endl;
    cout << ellipse.Area() << endl;
    cout << ellipse.InterfaceType().name() << endl;
    cout << ellipse.ImplementationType().name() << endl;

    cout << "shape = &ellipse: " << endl;
    cout << shape->Description() << endl;
    cout << shape->Area() << endl;
    cout << shape->InterfaceType().name() << endl;
    cout << shape->ImplementationType().name() << endl;

    // Gọi phương thức Description thông qua dynamic_cast để chuyển đổi con trỏ
    cout << dynamic_cast<Ellipse*>(shape)->Description() << endl;

    return 0; // Không có lỗi
}
