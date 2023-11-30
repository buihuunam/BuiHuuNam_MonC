#include <iostream>
#include <cstring>

using namespace std;

// Lớp cơ sở đại diện cho xe đạp
class Bike {
private:
    char* brand; // Hiệu xe

public:
    // Constructor
    Bike(const char* b) {
        brand = new char[strlen(b) + 1];
        strcpy(brand, b);
    }

    // Destructor
    virtual ~Bike() {
        delete[] brand;
    }

    // Copy constructor
    Bike(const Bike& other) {
        brand = new char[strlen(other.brand) + 1];
        strcpy(brand, other.brand);
    }

    // Copy assignment operator
    Bike& operator=(const Bike& other) {
        if (this != &other) {
            delete[] brand;
            brand = new char[strlen(other.brand) + 1];
            strcpy(brand, other.brand);
        }
        return *this;
    }

    // Move constructor
    Bike(Bike&& other) noexcept {
        brand = other.brand;
        other.brand = nullptr;
    }

    // Move assignment operator
    Bike& operator=(Bike&& other) noexcept {
        if (this != &other) {
            delete[] brand;
            brand = other.brand;
            other.brand = nullptr;
        }
        return *this;
    }

    // Phương thức ảo để di chuyển xe với thời gian t1
    virtual void move(int t1) {
        cout << brand << ":" << t1 * 12 << " ";
    }
};

// Lớp kế thừa từ Bike, đại diện cho xe đạp điện
class EBike : public Bike {
public:
    // Constructor
    EBike(const char* b) : Bike(b) {}

    // Triển khai phương thức move để di chuyển xe đạp điện với thời gian t2
    void move(int t2) override {
        Bike::move(t2 * 2);
    }
};

// Hàm hiển thị thông tin di chuyển của các loại xe
void display(Bike& a, EBike& b) {
    a.move(2); // Gọi phương thức move của Bike
    b.move(2); // Gọi phương thức move của EBike
}

int main() {
    // Tạo hai đối tượng EBike
    EBike b1("EBike1");
    EBike b2("EBike2");

    // Hiển thị thông tin di chuyển của các xe
    display(b1, b2);

    return 0;
}

