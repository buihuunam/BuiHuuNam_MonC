#include <iostream>
#include <string>

// Sử dụng namespace std để ngắn gọn hóa việc sử dụng các thành phần của nó
using namespace std;

// Định nghĩa cấu trúc cho dữ liệu về một phòng ban của công ty
struct CompanyDivision {
    string divisionName;   // Tên phòng ban (ví dụ: East, West, North, South)
    double firstQuarterSales;   // Doanh số quý 1
    double secondQuarterSales;  // Doanh số quý 2
    double thirdQuarterSales;   // Doanh số quý 3
    double fourthQuarterSales;  // Doanh số quý 4
    double totalAnnualSales;    // Tổng doanh số hàng năm
    double averageQuarterlySales; // Doanh số trung bình mỗi quý
};

// Hàm để nhập doanh số cho mỗi phòng ban và tính tổng, trung bình
void nhapVaTinhToan(CompanyDivision& phongBan) {
    cout << "Nhập doanh số cho phòng ban " << phongBan.divisionName << ":" << endl;

    do {
        cout << "Doanh số quý 1: ";
        cin >> phongBan.firstQuarterSales;
        if (phongBan.firstQuarterSales < 0) {
            cout << "Vui lòng nhập số không âm." << endl;
        }
    } while (phongBan.firstQuarterSales < 0);

    do {
        cout << "Doanh số quý 2: ";
        cin >> phongBan.secondQuarterSales;
        if (phongBan.secondQuarterSales < 0) {
            cout << "Vui lòng nhập số không âm." << endl;
        }
    } while (phongBan.secondQuarterSales < 0);

    do {
        cout << "Doanh số quý 3: ";
        cin >> phongBan.thirdQuarterSales;
        if (phongBan.thirdQuarterSales < 0) {
            cout << "Vui lòng nhập số không âm." << endl;
        }
    } while (phongBan.thirdQuarterSales < 0);

    do {
        cout << "Doanh số quý 4: ";
        cin >> phongBan.fourthQuarterSales;
        if (phongBan.fourthQuarterSales < 0) {
            cout << "Vui lòng nhập số không âm." << endl;
        }
    } while (phongBan.fourthQuarterSales < 0);

    // Tính toán tổng và doanh số trung bình
    phongBan.totalAnnualSales = phongBan.firstQuarterSales + phongBan.secondQuarterSales +
                                phongBan.thirdQuarterSales + phongBan.fourthQuarterSales;
    phongBan.averageQuarterlySales = phongBan.totalAnnualSales / 4;
}

// Hàm để hiển thị thông tin về mỗi phòng ban
void hienThiThongTin(const CompanyDivision& phongBan) {
    cout << "\nThông tin về phòng ban " << phongBan.divisionName << ":" << endl;
    cout << "Doanh số quý 1: " << phongBan.firstQuarterSales << endl;
    cout << "Doanh số quý 2: " << phongBan.secondQuarterSales << endl;
    cout << "Doanh số quý 3: " << phongBan.thirdQuarterSales << endl;
    cout << "Doanh số quý 4: " << phongBan.fourthQuarterSales << endl;
    cout << "Tổng doanh số hàng năm: " << phongBan.totalAnnualSales << endl;
    cout << "Doanh số trung bình mỗi quý: " << phongBan.averageQuarterlySales << endl;
}

int main() {
    // Tạo bốn biến CompanyDivision để đại diện cho các phòng ban khác nhau
    CompanyDivision phongBanEast = {"East"};
    CompanyDivision phongBanWest = {"West"};
    CompanyDivision phongBanNorth = {"North"};
    CompanyDivision phongBanSouth = {"South"};

    // Nhập và tính toán thông tin cho từng phòng ban
    nhapVaTinhToan(phongBanEast);
    nhapVaTinhToan(phongBanWest);
    nhapVaTinhToan(phongBanNorth);
    nhapVaTinhToan(phongBanSouth);

    // Hiển thị thông tin về từng phòng ban
    hienThiThongTin(phongBanEast);
    hienThiThongTin(phongBanWest);
    hienThiThongTin(phongBanNorth);
    hienThiThongTin(phongBanSouth);

    return 0;
}
