#include <iostream>
#include <limits> // Thư viện để sử dụng numeric_limits
using namespace std;

// Hàm để nhập điểm của một giám khảo và kiểm tra tính hợp lệ
void getJudgeData(double &score) {
    do {
        cout << "Nhap diem cua mot giam khao (tu 0 den 10): ";
        cin >> score;

        // Kiểm tra tính hợp lệ của điểm
        if (cin.fail() || score < 0 || score > 10) {
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

// Hàm để tìm điểm cao nhất trong năm điểm
int findHighest(double scores[]) {
    int highestIndex = 0;

    for (int i = 1; i < 5; ++i) {
        if (scores[i] > scores[highestIndex]) {
            highestIndex = i;
        }
    }

    return highestIndex;
}

// Hàm để tính và hiển thị trung bình của ba điểm cao nhất
void calcScore(double scores[]) {
    // Tìm và loại bỏ điểm thấp nhất và cao nhất
    int lowestIndex = findLowest(scores);
    int highestIndex = findHighest(scores);
    scores[lowestIndex] = 0;
    scores[highestIndex] = 0;

    // Tính tổng của ba điểm cao nhất
    double total = 0;
    int count = 0;
    for (int i = 0; i < 5; ++i) {
        if (scores[i] != 0) {
            total += scores[i];
            count++;
        }
    }

    // Tính và hiển thị trung bình
    double average = total / count;
    cout << "Diem cuoi cung cua thi sinh la: " << average << endl;
}

int main() {
    double scores[5];

    // Nhập điểm từ năm giám khảo
    for (int i = 0; i < 5; ++i) {
        getJudgeData(scores[i]);
    }

    // Gọi hàm để tính và hiển thị trung bình của ba điểm cao nhất
    calcScore(scores);

    return 0;
}
