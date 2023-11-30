#include <iostream>
#include <string>

using namespace std;

// Định nghĩa cấu trúc cho dữ liệu của người nói
struct Speaker {
    string name;           // Tên người nói
    string phoneNumber;    // Số điện thoại
    string speakingTopic;  // Chủ đề nói
    double feeRequired;    // Chi phí yêu cầu
};

// Hàm nhập thông tin cho một người nói
void nhapThongTinNguoiNoi(Speaker& nguoiNoi) {
    cout << "Nhập thông tin người nói:" << endl;

    cout << "Tên người nói: ";
    getline(cin, nguoiNoi.name);

    cout << "Số điện thoại: ";
    getline(cin, nguoiNoi.phoneNumber);

    cout << "Chủ đề nói: ";
    getline(cin, nguoiNoi.speakingTopic);

    // Nhập và kiểm tra tính hợp lệ chi phí yêu cầu
    do {
        cout << "Chi phí yêu cầu: $";
        cin >> nguoiNoi.feeRequired;
        if (nguoiNoi.feeRequired < 0) {
            cout << "Vui lòng không nhập số âm cho chi phí yêu cầu." << endl;
        }
    } while (nguoiNoi.feeRequired < 0);

    cin.ignore(); // Đọc dấu xuống dòng còn lại
}

// Hàm hiển thị thông tin của một người nói
void hienThiThongTinNguoiNoi(const Speaker& nguoiNoi) {
    cout << "\nThông tin người nói:" << endl;
    cout << "Tên người nói: " << nguoiNoi.name << endl;
    cout << "Số điện thoại: " << nguoiNoi.phoneNumber << endl;
    cout << "Chủ đề nói: " << nguoiNoi.speakingTopic << endl;
    cout << "Chi phí yêu cầu: $" << nguoiNoi.feeRequired << endl;
}

int main() {
    const int SONGUOINOI = 10;
    Speaker danhSachNguoiNoi[SONGUOINOI];

    int luaChon;
    int index;

    do {
        cout << "\n** Menu **" << endl;
        cout << "1. Nhập thông tin người nói" << endl;
        cout << "2. Hiển thị thông tin tất cả người nói" << endl;
        cout << "3. Hiển thị thông tin một người nói" << endl;
        cout << "4. Thoát" << endl;
        cout << "Chọn một lựa chọn (1-4): ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "Chọn số người nói (1-" << SONGUOINOI << "): ";
                cin >> index;
                cin.ignore();
                if (index >= 1 && index <= SONGUOINOI) {
                    nhapThongTinNguoiNoi(danhSachNguoiNoi[index - 1]);
                } else {
                    cout << "Số người nói không hợp lệ." << endl;
                }
                break;
            case 2:
                for (int i = 0; i < SONGUOINOI; ++i) {
                    hienThiThongTinNguoiNoi(danhSachNguoiNoi[i]);
                }
                break;
            case 3:
                cout << "Chọn số người nói (1-" << SONGUOINOI << "): ";
                cin >> index;
                if (index >= 1 && index <= SONGUOINOI) {
                    hienThiThongTinNguoiNoi(danhSachNguoiNoi[index - 1]);
                } else {
                    cout << "Số người nói không hợp lệ." << endl;
                }
                break;
            case 4:
                cout << "Kết thúc chương trình." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
        }
    } while (luaChon != 4);

    return 0;
}
