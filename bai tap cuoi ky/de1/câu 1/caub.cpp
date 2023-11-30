#include <iostream>
using namespace std;

// Lớp cơ sở MayLoc
class MayLoc {
private:
    float m_tgian; // Thời gian sử dụng máy lọc

protected:
    virtual float congSuat(); // Phương thức ảo trừu tượng để tính công suất

    void setTgian(float t); // Thiết lập thời gian sử dụng máy lọc

public:
    MayLoc(); // Constructor mặc định
    float tinhLuongNuoc(); // Phương thức tính lượng nước được lọc
};

MayLoc::MayLoc() {
    this->m_tgian = 0;
}

void MayLoc::setTgian(float t) {
    this->m_tgian = t;
}

float MayLoc::tinhLuongNuoc() {
    return congSuat() * m_tgian;
}

float MayLoc::congSuat() {
    return 0;
}

// Lớp kế thừa từ MayLoc - MayLyTam
class MayLyTam : public MayLoc {
private:
    float m_cs; // Công suất của máy ly tâm

protected:
    float congSuat() override; // Override phương thức công suất

public:
    MayLyTam(float cs, float t); // Constructor với tham số
};

MayLyTam::MayLyTam(float cs, float t) {
    this->m_cs = cs;
    this->setTgian(t); // Sử dụng phương thức của lớp cơ sở để thiết lập thời gian
}

float MayLyTam::congSuat() {
    return this->m_cs;
}

int main() {
    // Tạo đối tượng MayLyTam thông qua con trỏ của lớp cơ sở MayLoc
    MayLoc *pm = new MayLyTam(81.9, 10);
    
    // In ra lượng nước được lọc
    cout << "Luong nuoc = " << pm->tinhLuongNuoc() << endl;

    // Giải phóng bộ nhớ
    delete pm;
    
    return 0;
}
