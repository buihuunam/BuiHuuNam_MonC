#include <iostream>

using namespace std;

class ComplexNumber {
private:
    int realPart;     // Phần thực (a)
    int imaginaryPart; // Phần ảo (b)

public:
    // Hàm tạo
    ComplexNumber(int a = 0, int b = 0) : realPart(a), imaginaryPart(b) {}

    // Phép cộng
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
    }

    // Phép trừ
    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(realPart - other.realPart, imaginaryPart - other.imaginaryPart);
    }

    // Phép đổi dấu
    ComplexNumber operator-() const {
        return ComplexNumber(-realPart, -imaginaryPart);
    }

    // Phép nhân
    ComplexNumber operator*(const ComplexNumber& other) const {
        int a = realPart;
        int b = imaginaryPart;
        int c = other.realPart;
        int d = other.imaginaryPart;

        int newRealPart = a * c + 7 * b * d;
        int newImaginaryPart = b * c + a * d;

        return ComplexNumber(newRealPart, newImaginaryPart);
    }

    // Hàm nhập
    void input() {
        cout << "Enter real part (a): ";
        cin >> realPart;
        cout << "Enter imaginary part (b): ";
        cin >> imaginaryPart;
    }

    // Hàm xuất
    void output() const {
        cout << realPart;
        if (imaginaryPart >= 0) {
            cout << " + " << imaginaryPart << "√7";
        } else {
            cout << " - " << -imaginaryPart << "√7";
        }
        cout << endl;
    }
};

int main() {
    // Thực hiện các thao tác trên kiểu số a + b√7
    ComplexNumber num1, num2, result;

    cout << "Enter the first complex number:\n";
    num1.input();

    cout << "Enter the second complex number:\n";
    num2.input();

    // Phép cộng
    result = num1 + num2;
    cout << "Sum: ";
    result.output();

    // Phép trừ
    result = num1 - num2;
    cout << "Difference: ";
    result.output();

    // Phép đổi dấu
    result = -num1;
    cout << "Negation of the first number: ";
    result.output();

    // Phép nhân
    result = num1 * num2;
    cout << "Product: ";
    result.output();

    return 0;
}
