#include <iostream>

using namespace std;

class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    // Constructor
    PhanSo(int tu = 0, int mau = 1) : tuSo(tu), mauSo(mau) {}

    // Phép toán cộng
    PhanSo operator+(const PhanSo& other) const {
        int newTu = tuSo * other.mauSo + mauSo * other.tuSo;
        int newMau = mauSo * other.mauSo;
        return PhanSo(newTu, newMau);
    }

    // Phép toán ++
    PhanSo operator++() {
        tuSo += mauSo;
        return *this;
    }

    // Phép toán +=
    void operator+=(const PhanSo& other) {
        tuSo = tuSo * other.mauSo + mauSo * other.tuSo;
        mauSo = mauSo * other.mauSo;
    }

    // Phép chuyển đổi từ PhanSo sang int
    operator int() const {
        return tuSo / mauSo;
    }

    // Xuất phân số
    friend ostream& operator<<(ostream& os, const PhanSo& ps) {
        os << ps.tuSo << "/" << ps.mauSo;
        return os;
    }
};

int main() {
    PhanSo a(1, 3), c;
    int b = 8;

    // Phép cộng giữa PhanSo và int, sau đó gán vào c
    c = a + (PhanSo)b;
    cout << "c = " << a << " + " << b << " = " << c << endl;

    // Phép ++ trên c và in ra màn hình
    cout << "++c: ";
    cout << "c = " << ++c << endl;

    // Phép cộng giữa a và c, sau đó gán lại vào a
    cout << "a = " << a << " + " << c << endl;
    a += c;

    // In ra màn hình giá trị mới của a
    cout << "a = " << a << endl;

    // Gán giá trị của a (sử dụng phép chuyển đổi) vào biến b
    b = static_cast<int>(a);

    // In ra màn hình giá trị của b
    cout << "b = " << b << endl;

    return 0;
}
