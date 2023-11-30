#include <iostream>
#include <string>

using namespace std;

// Định nghĩa cấu trúc cho dữ liệu của một cầu thủ bóng đá
struct SoccerPlayer {
    string playerName;  // Tên cầu thủ
    int playerNumber;   // Số áo cầu thủ
    int pointsScored;   // Số điểm ghi được bởi cầu thủ
};

int main() {
    const int SOCAUTHU = 12;
    SoccerPlayer doiBong[SOCAUTHU]; // Mảng 12 cầu thủ

    // Nhập dữ liệu cho từng cầu thủ
    for (int i = 0; i < SOCAUTHU; ++i) {
        cout << "\nNhập thông tin cho cầu thủ thứ " << i + 1 << ":" << endl;

        cout << "Tên cầu thủ: ";
        getline(cin, doiBong[i].playerName);

        // Nhập và kiểm tra tính hợp lệ số áo cầu thủ
        do {
            cout << "Số áo cầu thủ: ";
            cin >> doiBong[i].playerNumber;
            if (doiBong[i].playerNumber < 0) {
                cout << "Vui lòng nhập số không âm." << endl;
            }
        } while (doiBong[i].playerNumber < 0);

        // Nhập và kiểm tra tính hợp lệ số điểm ghi được
        do {
            cout << "Số điểm ghi được: ";
            cin >> doiBong[i].pointsScored;
            if (doiBong[i].pointsScored < 0) {
                cout << "Vui lòng nhập số không âm." << endl;
            }
        } while (doiBong[i].pointsScored < 0);

        cin.ignore(); // Đọc dấu xuống dòng còn lại
    }

    // Hiển thị bảng thông tin cầu thủ
    cout << "\nBảng thông tin cầu thủ:" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "| Số áo | Tên cầu thủ            | Điểm ghi được |" << endl;
    cout << "------------------------------------------------------" << endl;

    // Tính tổng điểm của đội bóng và tìm cầu thủ có số điểm cao nhất
    int tongDiemDoiBong = 0;
    int maxDiem = doiBong[0].pointsScored;
    string tenCauThuMaxDiem = doiBong[0].playerName;

    for (int i = 0; i < SOCAUTHU; ++i) {
        cout << "| " << doiBong[i].playerNumber << "\t| " << doiBong[i].playerName << "\t\t| " << doiBong[i].pointsScored << "\t\t|" << endl;
        tongDiemDoiBong += doiBong[i].pointsScored;

        // Tìm cầu thủ có số điểm cao nhất
        if (doiBong[i].pointsScored > maxDiem) {
            maxDiem = doiBong[i].pointsScored;
            tenCauThuMaxDiem = doiBong[i].playerName;
        }
    }

    cout << "------------------------------------------------------" << endl;
    cout << "Tổng điểm đội bóng: " << tongDiemDoiBong << endl;
    cout << "Cầu thủ có số điểm cao nhất: " << tenCauThuMaxDiem << " (" << maxDiem << " điểm)" << endl;

    return 0;
}
