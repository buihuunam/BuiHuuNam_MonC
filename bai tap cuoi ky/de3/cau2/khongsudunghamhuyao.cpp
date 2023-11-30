#include <iostream>
using namespace std;

// Lớp cơ sở
class Base {
public:
    // Hàm hủy của lớp cơ sở
    ~Base() {
        cout << "Base destructor\n";
    }
};

// Lớp dẫn xuất từ lớp cơ sở
class Derived : public Base {
public:
    // Hàm hủy của lớp dẫn xuất
    ~Derived() {
        cout << "Derived destructor\n";
    }
};

int main() {
    // Tạo một đối tượng con trỏ thuộc lớp cơ sở và gán nó giá trị của đối tượng lớp dẫn xuất
    Base* obj = new Derived();

    // Xóa đối tượng con trỏ, chỉ gọi hàm hủy của lớp cơ sở
    delete obj;

    return 0;
}
