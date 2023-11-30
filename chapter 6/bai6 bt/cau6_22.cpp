#include <iostream>
#include <cmath> // Thư viện để sử dụng hàm sqrt
using namespace std;

// Hàm kiểm tra xem một số có phải là số nguyên tố không
bool isPrime(int num) {
    // Nếu số nhỏ hơn 2, không phải là số nguyên tố
    if (num < 2) {
        return false;
    }

    // Kiểm tra từ 2 đến căn bậc hai của số đó
    for (int i = 2; i <= sqrt(num); ++i) {
        // Nếu số chia hết cho một số từ 2 đến căn bậc hai của nó, không phải là số nguyên tố
        if (num % i == 0) {
            return false;
        }
    }

    // Nếu không chia hết cho bất kỳ số nào, là số nguyên tố
    return true;
}

// Hàm chính
int main() {
    int number;

    // Nhập số từ người dùng
    cout << "Enter a number: ";
    cin >> number;

    // Kiểm tra và hiển thị kết quả
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is not a prime number." << endl;
    }

    return 0;
}
