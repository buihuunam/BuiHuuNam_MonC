#include <iostream>
#include <string>

using namespace std;

// Giao diện chưa các phương thức cần được triển khai bởi các lớp con
class IFace {
public:
    virtual void show() = 0;         // Phương thức hiển thị thông tin
    virtual IFace* clone() = 0;      // Phương thức tạo bản sao
    virtual ~IFace() {}              // Hàm hủy ảo cho giao diện
};

// Lớp cơ sở đại diện cho khuôn mặt với hình dạng
class Face : public IFace {
private:
    string shape; // Hình dạng khuôn mặt

protected:
    string getShape(); // Phương thức bảo vệ trả về hình dạng

public:
    // Constructor
    Face(string sh) : shape(sh) {}

    // Override phương thức show từ giao diện IFace
    void show() override {
        cout << "Shape: " << shape << endl;
    }
};

// Lớp kế thừa từ Face và triển khai giao diện IFace
class EyedFace : public Face {
private:
    int eyes; // Số mắt của khuôn mặt

public:
    // Constructor
    EyedFace(string sh, int ey) : Face(sh), eyes(ey) {}

    // Override phương thức show từ lớp cơ sở Face
    void show() override {
        Face::show(); // Gọi phương thức show của lớp cơ sở
        cout << "Eyes: " << eyes << endl;
    }

    // Override phương thức clone từ giao diện IFace
    IFace* clone() override {
        return new EyedFace(getShape(), eyes);
    }
};

int main() {
    // Tạo đối tượng EyedFace
    EyedFace eyedFace("Round", 2);

    // Gọi phương thức show của EyedFace
    eyedFace.show();

    // Tạo bản sao của EyedFace sử dụng phương thức clone
    IFace* clonedFace = eyedFace.clone();

    // Gọi phương thức show của bản sao
    clonedFace->show();

    // Giải phóng bộ nhớ của bản sao
    delete clonedFace;

    return 0;
}
