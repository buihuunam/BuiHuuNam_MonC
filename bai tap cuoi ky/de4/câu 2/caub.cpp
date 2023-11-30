#include <iostream>
#include <string>

using namespace std;

// Giao diện (interface) IFace định nghĩa hai hàm thuần ảo và một hàm hủy ảo.
class IFace {
public:
    virtual void show() = 0; // Hàm hiển thị thông tin
    virtual IFace* clone() = 0; // Hàm tạo bản sao của đối tượng
    virtual ~IFace() {} // Hàm hủy ảo
};

// Lớp Face kế thừa từ giao diện IFace và triển khai các hàm ảo của nó.
class Face : public IFace {
private:
    string shape; // Thuộc tính hình dạng

protected:
    string getShape(); // Hàm bảo vệ để lấy giá trị hình dạng

public:
    // Hàm tạo với tham số là hình dạng, khởi tạo thuộc tính shape.
    Face(string sh) : shape(sh) {}

    // Triển khai hàm hiển thị thông tin, in ra màn hình "Shape: " kèm theo hình dạng.
    void show() override {
        cout << "Shape: " << shape << endl;
    }

    // Triển khai hàm tạo bản sao của đối tượng.
    IFace* clone() override {
        return new Face(getShape());
    }
};

// Hàm kiểm tra Face với một đối tượng IFace và hai bản sao của nó.
void testFace(IFace* fc) {
    IFace* a[3] = { fc, fc->clone(), fc->clone() };
    for (int i = 0; i < 3; i++) {
        a[i]->show();
    }
    cout << "The same 3 lines?" << endl;
}

int main() {
    // Tạo một đối tượng Face không có hình dạng cụ thể.
    Face fc("");  // Thêm một giá trị rỗng để khớp với hàm tạo.

    // Tạo một đối tượng Face với hình dạng là "Rectangle".
    Face fc1("Rectangle");

    // Kiểm tra đối tượng fc1 và hai bản sao của nó bằng hàm testFace.
    testFace(&fc1);

    return 0;
}
