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
    virtual void show() override {
        cout << "Shape: " << shape << endl;
    }
};

// Lớp kế thừa từ Face và triển khai giao diện IFace
class EyedFace : public Face {
private:
    static int objectCount; // Biến tĩnh để đếm số đối tượng

public:
    // Constructor
    EyedFace(string sh) : Face(sh) {
        objectCount++;
    }

    // Hàm hủy
    ~EyedFace() {
        objectCount--;
    }

    // Override phương thức clone từ giao diện IFace
    IFace* clone() override {
        EyedFace* clone = new EyedFace(getShape());
        objectCount++;
        return clone;
    }

    // Hàm trả về số đối tượng EyedFace hiện tại.
    static int getObjectCount() {
        return objectCount;
    }
};

// Khởi tạo biến tĩnh objectCount
int EyedFace::objectCount = 0;

// Hàm thử nghiệm IFace với đối tượng được truyền vào
void testFace(IFace* fc) {
    IFace* a[3] = { fc, fc->clone(), fc->clone() };
    for (int i = 0; i < 3; i++) {
        a[i]->show();
    }
    cout << "The same 3 lines?" << endl;
}

int main() {
    // Tạo một đối tượng EyedFace
    EyedFace* efc1 = new EyedFace("Square");

    // Thử nghiệm IFace với đối tượng EyedFace
    testFace(efc1);

    // Hiển thị số đối tượng EyedFace hiện tại trong bộ nhớ
    cout << "Number of EyedFace objects in memory: " << EyedFace::getObjectCount() << endl;

    // Giải phóng bộ nhớ của đối tượng efc1
    delete efc1;

    return 0;
}
