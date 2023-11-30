#include <iostream>
#include <iomanip>

using namespace std;

// Hàm để nhập số ngày tổng cộng trên chuyến đi
int nhapSoNgay() {
    int soNgay;
    while (true) {
        cout << "Nhập tổng số ngày trên chuyến đi: ";
        cin >> soNgay;
        if (soNgay < 1) {
            cout << "Vui lòng nhập một số ngày hợp lệ (ít nhất là 1)." << endl;
        } else {
            return soNgay;
        }
    }
}

// Hàm để nhập giờ khởi hành và giờ đến nhà cuối cùng
void nhapGioKhoiHanhDenNha(string &gioKhoiHanh, string &gioDenNha) {
    cout << "Nhập thời gian khởi hành vào ngày đầu tiên (HH:MM AM/PM): ";
    cin.ignore();  // Loại bỏ kí tự '\n' từ bước nhập trước đó
    getline(cin, gioKhoiHanh);

    cout << "Nhập thời gian đến nhà vào ngày cuối cùng (HH:MM AM/PM): ";
    getline(cin, gioDenNha);
}

// Hàm để nhập số tiền của vé máy bay khứ hồi
double nhapTienVeMayBay() {
    double tienVe;
    while (true) {
        cout << "Nhập số tiền của vé máy bay khứ hồi: $";
        cin >> tienVe;
        if (tienVe < 0) {
            cout << "Vui lòng nhập một số không âm." << endl;
        } else {
            return tienVe;
        }
    }
}

// Hàm để nhập số tiền của việc thuê xe
double nhapTienThueXe() {
    double tienThueXe;
    while (true) {
        cout << "Nhập số tiền thuê xe: $";
        cin >> tienThueXe;
        if (tienThueXe < 0) {
            cout << "Vui lòng nhập một số không âm." << endl;
        } else {
            return tienThueXe;
        }
    }
}

// Hàm để nhập số dặm di chuyển bằng phương tiện cá nhân
double nhapSoDamDiChuyen() {
    double soDam;
    while (true) {
        cout << "Nhập số dặm di chuyển bằng phương tiện cá nhân: ";
        cin >> soDam;
        if (soDam < 0) {
            cout << "Vui lòng nhập một số không âm." << endl;
        } else {
            return soDam;
        }
    }
}

// Hàm để nhập chi phí đỗ xe
double nhapPhiDoXe() {
    double phiDoXe;
    while (true) {
        cout << "Nhập chi phí đỗ xe: $";
        cin >> phiDoXe;
        if (phiDoXe < 0) {
            cout << "Vui lòng nhập một số không âm." << endl;
        } else {
            return phiDoXe;
        }
    }
}

// Hàm để nhập chi phí taxi
double nhapPhiTaxi() {
    double phiTaxi;
    while (true) {
        cout << "Nhập chi phí taxi: $";
        cin >> phiTaxi;
        if (phiTaxi < 0) {
            cout << "Vui lòng nhập một số không âm." << endl;
        } else {
            return phiTaxi;
        }
    }
}

// Hàm để nhập chi phí đăng ký hội nghị
double nhapPhiDangKyHoiNghi() {
    double phiDangKyHoiNghi;
    while (true) {
        cout << "Nhập chi phí đăng ký hội nghị: $";
        cin >> phiDangKyHoiNghi;
        if (phiDangKyHoiNghi < 0) {
            cout << "Vui lòng nhập một số không âm." << endl;
        } else {
            return phiDangKyHoiNghi;
        }
    }
}

// Hàm để nhập chi phí khách sạn
double nhapChiPhiKhachSan() {
    double chiPhiKhachSan;
    while (true) {
        cout << "Nhập chi phí khách sạn (tối đa $90 mỗi đêm): $";
        cin >> chiPhiKhachSan;
        if (chiPhiKhachSan < 0) {
            cout << "Vui lòng nhập một số không âm." << endl;
        } else {
            return chiPhiKhachSan;
        }
    }
}

// Hàm để nhập chi phí ăn uống
double nhapChiPhiAnUong(string buaAn) {
    double chiPhi;
    while (true) {
        cout << "Nhập chi phí ăn trưa " << buaAn << ": $";
        cin >> chiPhi;
        if (chiPhi < 0) {
            cout << "Vui lòng nhập một số không âm." << endl;
        } else {
            return chiPhi;
        }
    }
}

// Hàm để tính tổng chi phí
double tinhTongChiPhi(double tienVeMayBay, double tienThueXe, double soDam, double phiDoXe, double phiTaxi, double phiDangKyHoiNghi, double chiPhiKhachSan, double chiPhiBuaAn) {
    double chiPhiXeCuaBan = soDam * 0.27; // Chi phí phương tiện cá nhân
    double tongChiPhi = tienVeMayBay + tienThueXe + chiPhiXeCuaBan + phiDoXe + phiTaxi + phiDangKyHoiNghi + chiPhiKhachSan + chiPhiBuaAn;
    return tongChiPhi;
}

// Hàm để tính toán và hiển thị kết quả cuối cùng
void hienThiKetQua(double tongChiPhi, double tongChiPhiChoPhep, double soDu, double soTietKiem) {
    cout << "Tổng chi phí: $" << fixed << setprecision(2) << tongChiPhi << endl;
    cout << "Tổng chi phí cho phép: $" << fixed << setprecision(2) << tongChiPhiChoPhep << endl;

    if (soDu > 0) {
        cout << "Số tiền cần thanh toán thêm: $" << fixed << setprecision(2) << soDu << endl;
        cout << "Nhân viên cần hoàn trả khoản thặng dư." << endl;
    } else if (soDu < 0) {
        cout << "Số tiền đã tiết kiệm: $" << fixed << setprecision(2) << abs(soDu) << endl;
        cout << "Nhân viên có thể giữ lại số tiền tiết kiệm." << endl;
    } else {
        cout << "Không có thặng dư hoặc tiết kiệm." << endl;
    }
}

// Hàm chính của chương trình
int main() {
    // Gọi các hàm khác để nhận dữ liệu đầu vào
    int soNgay = nhapSoNgay();
    string gioKhoiHanh, gioDenNha;
    nhapGioKhoiHanhDenNha(gioKhoiHanh, gioDenNha);
    double tienVeMayBay = nhapTienVeMayBay();
    double tienThueXe = nhapTienThueXe();
    double soDam = nhapSoDamDiChuyen();
    double phiDoXe = nhapPhiDoXe();
    double phiTaxi = nhapPhiTaxi();
    double phiDangKyHoiNghi = nhapPhiDangKyHoiNghi();
    double chiPhiKhachSan = nhapChiPhiKhachSan();
    
    // Hỏi và tính chi phí ăn trưa cho mỗi bữa
    double chiPhiBuaAn = nhapChiPhiAnUong("sáng") + nhapChiPhiAnUong("trưa") + nhapChiPhiAnUong("tối");

    // Gọi hàm để tính tổng chi phí
    double tongChiPhi = tinhTongChiPhi(tienVeMayBay, tienThueXe, soDam, phiDoXe, phiTaxi, phiDangKyHoiNghi, chiPhiKhachSan, chiPhiBuaAn);

    // Triển khai logic để tính tổng chi phí cho phép
    double tongChiPhiChoPhep = 0;  // Giả sử bạn cần tính toán chi phí cho phép

    // Tính số tiền phải trả thêm và số tiền đã tiết kiệm
    double soDu = max(0.0, tongChiPhi - tongChiPhiChoPhep);
    double soTietKiem = max(0.0, tongChiPhiChoPhep - tongChiPhi);

    // Gọi hàm để hiển thị kết quả
    hienThiKetQua(tongChiPhi, tongChiPhiChoPhep, soDu, soTietKiem);

    return 0;
}
