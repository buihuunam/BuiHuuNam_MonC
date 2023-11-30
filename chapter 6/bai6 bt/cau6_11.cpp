#include <iostream>
#include <limits> // Thư viện để sử dụng numeric_limits
using namespace std;

// Hàm để nhập điểm kiểm tra và kiểm tra tính hợp lệ
void getScore(double &score) {
    do {
        cout << "Nhap diem kiem tra (tu 0 den 100): ";
        cin >> score;

        // Kiểm tra tính hợp lệ của điểm
        if (cin.fail() || score < 0 || score > 100) {
            cin.clear(); // Xóa trạng thái lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Loại bỏ dữ liệu nhập không hợp lệ
            cout << "Diem khong hop le. Vui long nhap lai.\n";
        } else {
            break; // Nếu điểm hợp lệ, thoát khỏi vòng lặp
        }
    } while (true);
}

// Hàm để tìm điểm thấp nhất trong năm điểm
int findLowest(double scores[]) {
    int lowestIndex = 0;

    for (int i = 1; i < 5; ++i) {
        if (scores[i] < scores[lowestIndex]) {
            lowestIndex = i;
        }
    }

    return lowestIndex;
}

// Hàm để tính và hiển thị trung bình của bốn điểm cao nhất
void calcAverage(double scores[]) {
    // Tìm và loại bỏ điểm thấp nhất
    int lowestIndex = findLowest(scores);
    scores[lowestIndex] = 0;

    // Tính tổng của bốn điểm cao nhất
    double total = 0;
    for (int i = 0; i < 5; ++i) {
        total += scores[i];
    }

    // Tính và hiển thị trung bình
    double average = total / 4;
    cout << "Trung binh cua bon diem cao nhat la: " << average << endl;
}

int main() {
    double scores[5];

    // Nhập điểm cho năm kỳ kiểm tra
    for (int i = 0; i < 5; ++i) {
        getScore(scores[i]);
    }

    // Gọi hàm để tính và hiển thị trung bình của bốn điểm cao nhất
    calcAverage(scores);

    return 0;
}
