#include <iostream>
#include <string>

using namespace std;

struct Speaker {
    string name;
    string phoneNumber;
    string speakingTopic;
    double feeRequired;
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

// Hàm tìm kiếm người nói theo chủ đề
void timKiemTheoChuDe(const Speaker danhSachNguoiNoi[], int soNguoiNoi, const string& chuDe) {
    bool timThay = false;

    for (int i = 0; i < soNguoiNoi; ++i) {
        // Nếu chủ đề nói chứa từ khóa cần tìm kiếm
        if (danhSachNguoiNoi[i].speakingTopic.find(chuDe) != string::npos) {
            hienThiThongTinNguoiNoi(danhSachNguoiNoi[i]);
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Không tìm thấy người nói với chủ đề chứa \"" << chuDe << "\"." << endl;
    }
}

int main() {
    const int SONGUOINOI = 10;
    Speaker danhSachNguoiNoi[SONGUOINOI];

    int luaChon;
    int index;
    string chuDeTimKiem;

    do {
        cout << "\n** Menu **" << endl;
        cout << "1. Nhập thông tin người nói" << endl;
        cout << "2. Hiển thị thông tin tất cả người nói" << endl;
        cout << "3. Hiển thị thông tin một người nói" << endl;
        cout << "4. Tìm kiếm người nói theo chủ đề" << endl;
        cout << "5. Thoát" << endl;
        cout << "Chọn một lựa chọn (1-5): ";
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
                cout << "Nhập từ khóa chủ đề cần tìm kiếm: ";
                cin.ignore(); // Đọc dấu xuống dòng còn lại
                getline(cin, chuDeTimKiem);
                timKiemTheoChuDe(danhSachNguoiNoi, SONGUOINOI, chuDeTimKiem);
                break;
            case 5:
                cout << "Kết thúc chương trình." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
        }
    } while (luaChon != 5);

    return 0;
}
