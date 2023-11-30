#include <iostream>

using namespace std;

int countCharacters(const char* str) {
    int count = 0;

    // Duyệt qua chuỗi và đếm số ký tự
    while (*str != '\0') {
        count++;
        str++;
    }

    return count;
}

int main() {
    // Khai báo một mảng ký tự để lưu chuỗi
    const int MAX_SIZE = 100;
    char inputString[MAX_SIZE];

    // Nhập chuỗi từ người dùng
    cout << "Enter a string: ";
    cin.getline(inputString, MAX_SIZE);

    // Gọi hàm để đếm số ký tự
    int charCount = countCharacters(inputString);

    // Hiển thị kết quả
    cout << "Number of characters in the string: " << charCount << endl;

    return 0;
}
