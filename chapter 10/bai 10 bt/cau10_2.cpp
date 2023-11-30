#include <iostream>

using namespace std;

// Function to display the contents of a C-string backward
void displayBackward(const char* str) {
    // Duyệt qua chuỗi để tìm chiều dài của nó
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    // Hiển thị nội dung của chuỗi theo chiều ngược lại
    for (int i = length - 1; i >= 0; --i) {
        cout << str[i];
    }

    cout << endl;
}

int main() {
    // Khai báo một mảng ký tự để lưu chuỗi
    const int MAX_SIZE = 100;
    char inputString[MAX_SIZE];

    // Nhập chuỗi từ người dùng
    cout << "Enter a string: ";
    cin.getline(inputString, MAX_SIZE);

    // Gọi hàm để hiển thị chuỗi theo chiều ngược lại
    cout << "String backward: ";
    displayBackward(inputString);

    return 0;
}
