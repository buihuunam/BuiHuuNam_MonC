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
    this->setTgian(t); /*1 - sử dụng setTgian thay vì m_tgian để giữ nguyên phạm vi bảo vệ*/
}

float MayLyTam::congSuat() {
    return this->m_cs;
}

int main() {
    MayLoc *pm = new MayLoc();
    // if (pm->congSuat() < 5) /*2*/ // Bạn có thể xoá dòng này để không có điều kiện kiểm tra
    {
        MayLyTam ml(81.9, 10);
        pm = &ml; /*3*/
        cout << "Luong nuoc = " << pm->tinhLuongNuoc();
    }
    delete pm; /*4*/
    return 0;
}
