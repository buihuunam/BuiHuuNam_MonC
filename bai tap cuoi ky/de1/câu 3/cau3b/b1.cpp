#include <iostream>
#include <vector>

using namespace std;
float don_gia_thue;
// Lớp cơ sở máy lọc
class MayLocNuoc {
public:
    virtual float tinhCongSuatThucTe() = 0;
    virtual float tinhChiPhiThue() = 0;
    virtual float tinhChiPhiSuDung() = 0;
    virtual float tinhLuongNuoc() = 0;
    virtual void nhapThongTin() = 0;
    virtual ~MayLocNuoc() {}
};

// Lớp con máy ly tâm kế thừa từ lớp cơ sở
class MayLyTam : public MayLocNuoc {
public:
    MayLyTam(float luongXang) : luong_xang(luongXang) {
        don_gia_thue = 50000;
    }

    float tinhCongSuatThucTe() override {
        return 0; // Máy ly tâm không ảnh hưởng đến công suất thực tế
    }

    float tinhChiPhiThue() override {
        return don_gia_thue;
    }

    float tinhChiPhiSuDung() override {
        return luong_xang * 20000;
    }

    float tinhLuongNuoc() override {
        return 0; // Máy ly tâm không ảnh hưởng đến lượng nước lọc được
    }

    void nhapThongTin() override {
        cout << "Nhap luong xang cho may ly tam: ";
        cin >> luong_xang;
    }

private:
    float luong_xang;
    float don_gia_thue;
};

// Lớp con máy xúc tác kế thừa từ lớp cơ sở
class MayXucTac : public MayLocNuoc {
public:
    MayXucTac(float don_gia_hoa_chat) : don_gia_hoa_chat(don_gia_hoa_chat) {
        don_gia_thue = 80000;
    }

    float tinhCongSuatThucTe() override {
        if (thoi_gian_su_dung < 10) {
            return cong_suat_loc * (luong_hoa_chat / 100);
        } else {
            return cong_suat_loc * (luong_hoa_chat / 100) / (thoi_gian_su_dung / 10);
        }
    }

    float tinhChiPhiThue() override {
        return don_gia_thue * thoi_gian_su_dung;
    }

    float tinhChiPhiSuDung() override {
        float cong_suat_thuc_te = tinhCongSuatThucTe();
        float luong_nuoc = cong_suat_thuc_te * thoi_gian_su_dung;
        return don_gia_thue * thoi_gian_su_dung + luong_nuoc * don_gia_hoa_chat;
    }

    float tinhLuongNuoc() override {
        return tinhCongSuatThucTe() * thoi_gian_su_dung;
    }

    void nhapThongTin() override {
        cout << "Nhap cong suat loc (m3/h): ";
        cin >> cong_suat_loc;
        cout << "Nhap thoi gian su dung (h): ";
        cin >> thoi_gian_su_dung;
        cout << "Nhap luong hoa chat (g): ";
        cin >> luong_hoa_chat;
    }

private:
    float cong_suat_loc;
    float thoi_gian_su_dung;
    float luong_hoa_chat;
    float don_gia_hoa_chat;
};

int main() {
    int soLuongMayLoc;
    cout << "Nhap so luong may loc: ";
    cin >> soLuongMayLoc;

    vector<MayLocNuoc*> danhSachMayLoc; // Vector để lưu trữ các đối tượng máy lọc

    // Nhập thông tin cho từng máy lọc
    for (int i = 0; i < soLuongMayLoc; i++) {
        cout << "Chon loai may loc (1 - May ly tam, 2 - May xuc tac): ";
        int luaChon;
        cin >> luaChon;

        MayLocNuoc* mayLoc;

        if (luaChon == 1) {
            mayLoc = new MayLyTam(0); // Khởi tạo máy ly tâm với lượng xăng mặc định (0)
        } else if (luaChon == 2) {
            mayLoc = new MayXucTac(10); // Khởi tạo máy xúc tác với đơn giá hóa chất là 10.000 đồng/g
        } else {
            cout << "Lua chon khong hop le." << endl;
            i--; // Nếu lựa chọn không hợp lệ, giảm biến đếm để nhập lại thông tin cho máy này
            continue;
        }

        mayLoc->nhapThongTin(); // Gọi hàm nhập thông tin tùy thuộc vào loại máy
        danhSachMayLoc.push_back(mayLoc);
    }

    // Tính toán và hiển thị tổng chi phí thuê, chi phí sử dụng, và lượng nước lọc được
    float tongChiPhiThue = 0;
    float tongChiPhiSuDung = 0;
    float tongLuongNuocLocDuoc = 0;

    for (MayLocNuoc* mayLoc : danhSachMayLoc) {
        tongChiPhiThue += mayLoc->tinhChiPhiThue();
        tongChiPhiSuDung += mayLoc->tinhChiPhiSuDung();
        tongLuongNuocLocDuoc += mayLoc->tinhLuongNuoc();
    }

    cout << "Tong chi phi thue: " << tongChiPhiThue << endl;
    cout << "Tong chi phi su dung: " << tongChiPhiSuDung << endl;
    cout << "Tong luong nuoc loc duoc: " << tongLuongNuocLocDuoc << endl;

    // Giải phóng bộ nhớ của các đối tượng đã được tạo
    for (MayLocNuoc* mayLoc : danhSachMayLoc) {
        delete mayLoc;
    }

    return 0;
}
