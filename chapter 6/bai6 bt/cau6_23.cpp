#include <iostream>
#include <fstream> // Thư viện để sử dụng file
using namespace std;

// Hàm kiểm tra xem một số có phải là số nguyên tố không
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    // Mở file để ghi danh sách các số nguyên tố
    ofstream outFile("prime_numbers.txt");

    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    // Ghi các số nguyên tố từ 1 đến 100 vào file
    for (int i = 1; i <= 100; ++i) {
        if (isPrime(i)) {
            outFile << i << endl;
        }
    }

    // Đóng file
    outFile.close();

    cout << "Prime numbers from 1 to 100 have been written to prime_numbers.txt." << endl;

    return 0;
}
