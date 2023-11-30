#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to count the number of words and average number of letters in a C-string
void countWordsAndAverage(const char* str, int& wordCount, double& averageLetters) {
    int totalLetters = 0;
    wordCount = 0;
    bool inWord = false;

    // Duyệt qua chuỗi để đếm số từ và tính tổng số ký tự
    while (*str != '\0') {
        if (!isspace(*str)) {
            // Nếu ký tự không phải là khoảng trắng và chưa ở trong một từ, tăng số từ lên 1
            if (!inWord) {
                inWord = true;
                wordCount++;
            }

            // Tăng tổng số ký tự lên 1
            totalLetters++;
        } else {
            // Nếu ký tự là khoảng trắng, đặt trạng thái vào ngoại lệ để bắt đầu một từ mới
            inWord = false;
        }

        str++;
    }

    // Tính trung bình số ký tự trong mỗi từ
    averageLetters = (wordCount == 0) ? 0 : static_cast<double>(totalLetters) / wordCount;
}

// Overloaded function for std::string
void countWordsAndAverage(const string& str, int& wordCount, double& averageLetters) {
    countWordsAndAverage(str.c_str(), wordCount, averageLetters);
}

int main() {
    // Khai báo một biến chuỗi để lưu chuỗi
    string inputString;

    // Nhập chuỗi từ người dùng
    cout << "Enter a string: ";
    getline(cin, inputString);

    // Gọi hàm để đếm số từ và trung bình số ký tự trong mỗi từ
    int wordCount;
    double averageLetters;
    countWordsAndAverage(inputString, wordCount, averageLetters);

    // Hiển thị kết quả
    cout << "Number of words in the string: " << wordCount << endl;
    cout << "Average number of letters in each word: " << averageLetters << endl;

    return 0;
}
