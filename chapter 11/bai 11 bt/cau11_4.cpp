#include <iostream>
#include <string>

// Sử dụng namespace std để ngắn gọn hóa việc sử dụng các thành phần của nó
using namespace std;

// Định nghĩa cấu trúc cho dữ liệu về thời tiết của một tháng
struct WeatherData {
    double totalRainfall;       // Tổng lượng mưa
    double highTemperature;     // Nhiệt độ cao nhất
    double lowTemperature;      // Nhiệt độ thấp nhất
    double averageTemperature;  // Nhiệt độ trung bình
};

// Hàm để nhập dữ liệu thời tiết cho mỗi tháng và tính toán giá trị cần thiết
void nhapDuLieuThoiTiet(WeatherData& thang) {
    cout << "Nhập dữ liệu thời tiết cho một tháng:" << endl;

    // Nhập lượng mưa và kiểm tra tính hợp lệ
    do {
        cout << "Tổng lượng mưa: ";
        cin >> thang.totalRainfall;
        if (thang.totalRainfall < 0) {
            cout << "Vui lòng nhập số không âm." << endl;
        }
    } while (thang.totalRainfall < 0);

    // Nhập nhiệt độ cao nhất và kiểm tra tính hợp lệ
    do {
        cout << "Nhiệt độ cao nhất: ";
        cin >> thang.highTemperature;
        if (thang.highTemperature < -100 || thang.highTemperature > 140) {
            cout << "Vui lòng nhập nhiệt độ trong khoảng từ -100 đến +140 độ Fahrenheit." << endl;
        }
    } while (thang.highTemperature < -100 || thang.highTemperature > 140);

    // Nhập nhiệt độ thấp nhất và kiểm tra tính hợp lệ
    do {
        cout << "Nhiệt độ thấp nhất: ";
        cin >> thang.lowTemperature;
        if (thang.lowTemperature < -100 || thang.lowTemperature > 140) {
            cout << "Vui lòng nhập nhiệt độ trong khoảng từ -100 đến +140 độ Fahrenheit." << endl;
        }
    } while (thang.lowTemperature < -100 || thang.lowTemperature > 140);

    // Tính toán nhiệt độ trung bình
    thang.averageTemperature = (thang.highTemperature + thang.lowTemperature) / 2;
}

int main() {
    const int soThangTrongNam = 12;
    WeatherData thoiTiet[soThangTrongNam]; // Mảng 12 cấu trúc để lưu trữ dữ liệu thời tiết cho cả năm

    // Nhập dữ liệu thời tiết cho từng tháng
    for (int i = 0; i < soThangTrongNam; ++i) {
        cout << "\nNhập dữ liệu cho tháng " << i + 1 << endl;
        nhapDuLieuThoiTiet(thoiTiet[i]);
    }

    // Tính toán và hiển thị thông tin thống kê
    double tongLuongMuaHangNam = 0;
    double nhietDoTrungBinhThang = 0;
    double nhietDoTrungBinhNam = 0;
    double nhietDoCaoNhatNam = thoiTiet[0].highTemperature;
    double nhietDoThapNhatNam = thoiTiet[0].lowTemperature;
    int thangCaoNhat = 1;
    int thangThapNhat = 1;

    for (int i = 0; i < soThangTrongNam; ++i) {
        tongLuongMuaHangNam += thoiTiet[i].totalRainfall;
        nhietDoTrungBinhThang += thoiTiet[i].averageTemperature;

        if (thoiTiet[i].highTemperature > nhietDoCaoNhatNam) {
            nhietDoCaoNhatNam = thoiTiet[i].highTemperature;
            thangCaoNhat = i + 1;
        }

        if (thoiTiet[i].lowTemperature < nhietDoThapNhatNam) {
            nhietDoThapNhatNam = thoiTiet[i].lowTemperature;
            thangThapNhat = i + 1;
        }
    }

    // Tính toán nhiệt độ trung bình hàng năm và hiển thị thông tin thống kê
    nhietDoTrungBinhNam = nhietDoTrungBinhThang / soThangTrongNam;
    cout << "\nThống kê về thời tiết:" << endl;
    cout << "Tổng lượng mưa hàng năm: " << tongLuongMuaHangNam << " inches" << endl;
    cout << "Nhiệt độ trung bình hàng năm: " << nhietDoTrungBinhNam << " degrees Fahrenheit" << endl;
    cout << "Nhiệt độ cao nhất trong năm: " << nhietDoCaoNhatNam << " degrees Fahrenheit (Tháng " << thangCaoNhat << ")" << endl;
    cout << "Nhiệt độ thấp nhất trong năm: " << nhietDoThapNhatNam << " degrees Fahrenheit (Tháng " << thangThapNhat << ")" << endl;

    return 0;
}
