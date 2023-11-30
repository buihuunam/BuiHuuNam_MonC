#include <iostream>
using namespace std;

class MayLoc {
private:
    float m_tgian;
protected:
    virtual float congSuat();
    void setTgian(float t);
public:
    MayLoc();
    float tinhLuongNuoc();
    float getCongSuat(); // Thêm hàm công cộng để truy cập congSuat()
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

float MayLoc::getCongSuat() {
    return congSuat(); // Cung cấp một cách công cộng để truy cập congSuat()
}

class MayLyTam : public MayLoc {
private:
    float m_cs;
protected:
    float congSuat();
public:
    MayLyTam(float cs, float t);
};

MayLyTam::MayLyTam(float cs, float t) {
    this->m_cs = cs;
    this->setTgian(t); /*1 - sử dụng setTgian thay vì truy cập trực tiếp m_tgian*/
}

float MayLyTam::congSuat() {
    return this->m_cs;
}

int main() {
    MayLoc *pm = new MayLoc();
    if (pm->getCongSuat() < 5) /*2*/ // Sử dụng hàm công cộng để truy cập congSuat()
    {
        MayLyTam ml(81.9, 10);
        pm = &ml; /*3*/
        cout << "Luong nuoc = " << pm->tinhLuongNuoc();
    }
    delete pm; /*4*/
    return 0;
}
