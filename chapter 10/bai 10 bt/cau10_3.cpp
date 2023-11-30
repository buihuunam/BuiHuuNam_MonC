#include <iostream>
#include <cctype> // For isspace function

using namespace std;

// Function to count the number of words in a C-string
int countWords(const char* str) {
    int wordCount = 0;
    bool inWord = false;

    // Duyệt qua chuỗi để đếm số từ
    while (*str != '\0') {
        if (!isspace(*str)) {
            // Nếu ký tự không phải là khoảng trắng và chưa ở trong một từ, tăng số từ lên 1
            if (!inWord) {
                inWord = true;
                wordCount++;
            }
        } else {
            // Nếu ký tự là khoảng trắng, đặt trạng thái vào ngoại lệ để bắt đầu một từ mới
            inWord = false;
        }

        str++;
    }

    return wordCount;
}

int main() {
    // Khai báo một mảng ký tự để lưu chuỗi
    const int MAX_SIZE = 100;
    char inputString[MAX_SIZE];

    // Nhập chuỗi từ người dùng
    cout << "Enter a string: ";
    cin.getline(inputString, MAX_SIZE);

    // Gọi hàm để đếm số từ và hiển thị kết quả
    int wordCount = countWords(inputString);
    cout << "Number of words in the string: " << wordCount << endl;

    return 0;
}
