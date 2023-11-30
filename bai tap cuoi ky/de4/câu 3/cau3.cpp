#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Lớp cơ bản đại diện cho một hợp đồng điện thoại
class HopDong {
protected:
    int soDienThoai;
    int soInternet;
    double cuocDienThoai;
    double cuocInternet;
    double thueBao;

public:
    // Hàm khởi tạo
    HopDong(int sdt, int si, double cdt, double ci, double tb)
        : soDienThoai(sdt), soInternet(si), cuocDienThoai(cdt), cuocInternet(ci), thueBao(tb) {}

    // Phương thức ảo để tính tổng cước của hợp đồng
    virtual double tinhCuoc() {
        return cuocDienThoai + cuocInternet + thueBao;
    }
};

// Lớp mở rộng từ HopDong, đại diện cho hợp đồng cơ bản
class HopDongBasic : public HopDong {
private:
    double donGiaDienThoai;
    double donGiaInternet;
    int nguongLuuLuongMienPhi;

public:
    // Hàm khởi tạo
    HopDongBasic(int sdt, int si, double cdt, double ci, double tb, double dgdt, double dgi, int nl) 
        : HopDong(sdt, si, cdt, ci, tb), donGiaDienThoai(dgdt), donGiaInternet(dgi), nguongLuuLuongMienPhi(nl) {}

    // Ghi đè phương thức tinhCuoc để tính cước theo quy tắc của hợp đồng cơ bản
    double tinhCuoc() override {
        if (soInternet <= nguongLuuLuongMienPhi) {
            return cuocDienThoai + thueBao;
        } else {
            return HopDong::tinhCuoc();
        }
    }

    // Getter cho thuộc tính nguongLuuLuongMienPhi
    int getNguongLuuLuongMienPhi() const {
        return nguongLuuLuongMienPhi;
    }
};

// Lớp mở rộng từ HopDongBasic, đại diện cho hợp đồng có dữ liệu miễn phí
class HopDongDataFree : public HopDongBasic {
private:
    double cuocLuuLuongVuotNguong;

public:
    // Hàm khởi tạo
    HopDongDataFree(int sdt, int si, double cdt, double ci, double tb, double dgdt, double dgi, int nl, double cllvn)
        : HopDongBasic(sdt, si, cdt, ci, tb, dgdt, dgi, nl), cuocLuuLuongVuotNguong(cllvn) {}

    // Ghi đè phương thức tinhCuoc để tính cước theo quy tắc của hợp đồng có dữ liệu miễn phí
    double tinhCuoc() override {
        if (soInternet > getNguongLuuLuongMienPhi()) {
            return HopDongBasic::tinhCuoc() + cuocLuuLuongVuotNguong;
        } else {
            return HopDongBasic::tinhCuoc();
        }
    }
};

// Lớp mở rộng từ HopDongBasic, đại diện cho hợp đồng có dữ liệu cố định
class HopDongDataFix : public HopDongBasic {
private:
    double mucCuocCoDinh;

public:
    // Hàm khởi tạo
    HopDongDataFix(int sdt, int si, double cdt, double ci, double tb, double dgdt, double dgi, int nl, double mccd)
        : HopDongBasic(sdt, si, cdt, ci, tb, dgdt, dgi, nl), mucCuocCoDinh(mccd) {
        cuocDienThoai -= cuocDienThoai * 0.1; // Giảm 10% giá cước
        cuocInternet -= cuocInternet * 0.1;
    }

    // Ghi đè phương thức tinhCuoc để tính cước theo quy tắc của hợp đồng có dữ liệu cố định
    double tinhCuoc() override {
        return mucCuocCoDinh + HopDongBasic::tinhCuoc();
    }
};

// Lớp đại diện cho thông tin cá nhân của khách hàng
class ThongTinKhachHang {
private:
    string hoTen;
    string chungMinhNhanDan;
    string diaChi;

public:
    // Hàm khởi tạo
    ThongTinKhachHang(string hoten, string cmnd, string diachi)
        : hoTen(hoten), chungMinhNhanDan(cmnd), diaChi(diachi) {}

    // Getter cho thông tin cá nhân
    string getHoTen() const {
        return hoTen;
    }

    string getChungMinhNhanDan() const {
        return chungMinhNhanDan;
    }

    string getDiaChi() const {
        return diaChi;
    }
};

// Lớp đại diện cho hợp đồng của một khách hàng
class HopDongKhachHang {
private:
    ThongTinKhachHang thongTinKhachHang;
    HopDong* hopDong;

public:
    // Hàm khởi tạo
    HopDongKhachHang(ThongTinKhachHang tt, HopDong* hd)
        : thongTinKhachHang(tt), hopDong(hd) {}

    // Phương thức để tính cước của hợp đồng và thông báo cước
    void tinhVaThongBaoCuoc() {
        double cuoc = hopDong->tinhCuoc();
        cout << "Thong tin khach hang: " << thongTinKhachHang.getHoTen() << ", CMND: " << thongTinKhachHang.getChungMinhNhanDan() << ", Dia chi: " << thongTinKhachHang.getDiaChi() << endl;
        cout << "Cuoc su dung: " << cuoc << " dong" << endl;
    }
};

int main() {
    // Tạo thông tin cá nhân của khách hàng
    ThongTinKhachHang thongTin1("Nguyen Van A", "123456789", "Ha Noi");
    ThongTinKhachHang thongTin2("Tran Thi B", "987654321", "Ho Chi Minh");

    // Tạo các đối tượng hợp đồng
    HopDong* hopdong1 = new HopDongBasic(123, 500, 200, 300, 50, 1000, 200, 100);
    HopDong* hopdong2 = new HopDongDataFree(456, 1000, 150, 400, 60, 800, 150, 200, 300);

    // Tạo các đối tượng hợp đồng khách hàng
    HopDongKhachHang hopdongKhachHang1(thongTin1, hopdong1);
    HopDongKhachHang hopdongKhachHang2(thongTin2, hopdong2);

    // Thông báo cước cho từng hợp đồng khách hàng
    hopdongKhachHang1.tinhVaThongBaoCuoc();
    hopdongKhachHang2.tinhVaThongBaoCuoc();

    // Giải phóng bộ nhớ
    delete hopdong1;
    delete hopdong2;

    return 0;
}
