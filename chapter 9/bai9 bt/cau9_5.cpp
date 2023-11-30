#include <iostream>

using namespace std;

// Hàm doSomething sử dụng con trỏ thay vì tham chiếu
int doSomething(int *x, int *y) {
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}

int main() {
    int num1, num2;

    // Nhập giá trị cho hai số nguyên từ người dùng
    cout << "Nhập giá trị cho số nguyên thứ nhất: ";
    cin >> num1;

    cout << "Nhập giá trị cho số nguyên thứ hai: ";
    cin >> num2;

    // Gọi hàm doSomething với con trỏ
    int result = doSomething(&num1, &num2);

    // Hiển thị kết quả
    cout << "Giá trị mới của số nguyên thứ nhất: " << num1 << endl;
    cout << "Giá trị mới của số nguyên thứ hai: " << num2 << endl;
    cout << "Kết quả của hàm doSomething: " << result << endl;

    return 0;
}
