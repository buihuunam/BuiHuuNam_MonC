#include <iostream>
#include <cstdlib> // Thư viện cho hàm rand và srand
#include <ctime>   // Thư viện cho hàm time
using namespace std;

// Hàm để mô phỏng việc tung đồng xu
void coinToss() {
    // Sinh số ngẫu nhiên trong khoảng 1 - 2
    int result = rand() % 2 + 1;

    // Hiển thị kết quả
    if (result == 1) {
        cout << "Heads" << endl;
    } else {
        cout << "Tails" << endl;
    }
}

int main() {
    // Thiết lập hạt giống cho hàm ngẫu nhiên
    srand(static_cast<unsigned int>(time(0)));

    // Nhập số lần tung đồng xu từ người dùng
    int numTosses;
    cout << "Nhap so lan tung dong xu: ";
    cin >> numTosses;

    // Gọi hàm để mô phỏng tung đồng xu theo số lần người dùng nhập
    for (int i = 0; i < numTosses; ++i) {
        cout << "Lan tung " << i + 1 << ": ";
        coinToss();
    }

    return 0;
}
