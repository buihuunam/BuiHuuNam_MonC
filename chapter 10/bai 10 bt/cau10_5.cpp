#include <iostream>
#include <cctype> // For toupper function
#include <cstring> // For strchr function

using namespace std;

// Function to capitalize the first character of each sentence in a C-string
void capitalizeSentences(char* str) {
    // Duyệt qua chuỗi để xử lý ký tự đầu tiên của mỗi câu
    for (int i = 0; str[i] != '\0'; ++i) {
        // Kiểm tra xem ký tự hiện tại có phải là dấu chấm hay không
        if (str[i] == '.') {
            // Tăng chỉ số i để trỏ đến ký tự sau dấu chấm
            i++;

            // Loại bỏ các khoảng trắng sau dấu chấm (nếu có)
            while (isspace(str[i])) {
                i++;
            }

            // Kiểm tra xem ký tự sau khoảng trắng có phải là ký tự chữ không
            if (isalpha(str[i])) {
                // Viết hoa ký tự đầu tiên của mỗi câu
                str[i] = toupper(str[i]);
            }
        }
    }
}

// Overloaded function for std::string
void capitalizeSentences(string& str) {
    capitalizeSentences(&str[0]);
}

int main() {
    // Khai báo một biến chuỗi để lưu chuỗi
    const int MAX_SIZE = 1000;
    char inputString[MAX_SIZE];

    // Nhập chuỗi từ người dùng
    cout << "Enter a string: ";
    cin.getline(inputString, MAX_SIZE);

    // Gọi hàm để viết hoa ký tự đầu tiên của mỗi câu
    capitalizeSentences(inputString);

    // Hiển thị chuỗi đã được sửa đổi
    cout << "Modified string: " << inputString << endl;

    return 0;
}
