// Tập tin PhanSo.h 
#ifndef _PhanSo_h 
#define _PhanSo_h 
#include <iostream> 
using namespace std; 
class PhanSo { 
    private: 
    int tu, mau; 
    public: 
    PhanSo(); 
    PhanSo(int t, int m); //constructor voới tham số
    friend ostream& operator << (ostream& out, const Phanso ps);// Toán tử xuất
    Phanso operator + (const Phanso& ps);// Toán tử cộng số nguyên
    Phanso operator + (int res);
    Phanso& operator++(); // Toán tử tăng ++ (tiền tố)
    Phanso operator += (const Phanso& ps); // Toán tử cộng vầ gán += 
    operator int() const; Chuyển đổi từ phân số sang int 
    }; 
    #endif