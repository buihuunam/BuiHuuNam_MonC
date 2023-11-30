#include <iostream>
using namespace std;

class MayLocNuoc {
public:
    virtual float tinhCongSuatThucTe() = 0;  // Phương thức ảo để tính công suất thực tế
    virtual float tinhChiPhiThue() = 0;      // Phương thức ảo để tính chi phí thuê
    virtual float tinhChiPhiSuDung() = 0;    // Phương thức ảo để tính chi phí sử dụng
    virtual float tinhLuongNuoc() = 0;       // Phương thức ảo để tính lượng nước

    virtual ~MayLocNuoc() {}  // Hàm hủy ảo

protected:
    float don_gia_thue;  // Đơn giá thuê (đồng/h)
};

class MayLyTam : public MayLocNuoc {
public:
    MayLyTam(float luong_xang) {
        this->luong_xang = luong_xang;
        don_gia_thue = 50000;  // Đơn giá thuê máy ly tâm
    }

    float tinhCongSuatThucTe() override {
        // Máy ly tâm không ảnh hưởng đến công suất thực tế
        return 0;
    }

    float tinhChiPhiThue() override {
        return don_gia_thue;  // Chi phí thuê máy ly tâm không phụ thuộc vào thời gian sử dụng
    }

    float tinhChiPhiSuDung() override {
        return luong_xang * 20000;  // Chi phí nhiên liệu của máy ly tâm
    }

    float tinhLuongNuoc() override {
        // Máy ly tâm không ảnh hưởng đến lượng nước lọc được
        return 0;
    }

private:
    float luong_xang;  // Lượng xăng sử dụng (lít)
};

class MayXucTac : public MayLocNuoc {
public:
    MayXucTac(float don_gia_hoa_chat) {
        this->don_gia_hoa_chat = don_gia_hoa_chat;
        don_gia_thue = 80000;  // Đơn giá thuê máy xúc tác
    }

    float tinhCongSuatThucTe() override {
        if (thoi_gian_su_dung < 10) {
            return cong_suat_loc * (luong_hoa_chat / 100);
        } else {
            return cong_suat_loc * (luong_hoa_chat / 100) / (thoi_gian_su_dung / 10);
        }
    }

    float tinhChiPhiThue() override {
        return don_gia_thue * thoi_gian_su_dung;  // Chi phí thuê máy xúc tác phụ thuộc vào thời gian sử dụng
    }

    float tinhChiPhiSuDung() override {
        float cong_suat_thuc_te = tinhCongSuatThucTe();
        float luong_nuoc = cong_suat_thuc_te * thoi_gian_su_dung;
        return don_gia_thue * thoi_gian_su_dung + luong_nuoc * don_gia_hoa_chat;
    }

    float tinhLuongNuoc() override {
        return tinhCongSuatThucTe() * thoi_gian_su_dung;
    }

    void nhap() {
        cout << "Nhap cong suat loc (m3/h): ";
        cin >> cong_suat_loc;
        cout << "Nhap thoi gian su dung (h): ";
        cin >> thoi_gian_su_dung;
        cout << "Nhap luong hoa chat (g): ";
        cin >> luong_hoa_chat;
    }

private:
    float cong_suat_loc;     // Công suất lọc (m3/h)
    float thoi_gian_su_dung; // Thời gian sử dụng (h)
    float luong_hoa_chat;    // Lượng hóa chất (g)
    float don_gia_hoa_chat;  // Đơn giá hóa chất (đồng/g)
};

int main() {
    int soLuongMayLyTam, soLuongMayXucTac;
    cout << "Nhap so luong may ly tam: ";
    cin >> soLuongMayLyTam;
    cout << "Nhap so luong may xuc tac: ";
    cin >> soLuongMayXucTac;

    float tongChiPhiThue = 0;
    float tongChiPhiSuDung = 0;
    float tongLuongNuocLocDuoc = 0;

    // Nhập thông tin và tính toán cho máy ly tâm
    for (int i = 0; i < soLuongMayLyTam; i++) {
        float luongXang;
        cout << "Nhap luong xang cho may ly tam " << i + 1 << ": ";
        cin >> luongXang;

        MayLyTam mayLyTam(luongXang);

        tongChiPhiThue += mayLyTam.tinhChiPhiThue();
        tongChiPhiSuDung += mayLyTam.tinhChiPhiSuDung();
        tongLuongNuocLocDuoc += mayLyTam.tinhLuongNuoc();
    }

    // Nhập thông tin và tính toán cho máy xúc tác
    for (int i = 0; i < soLuongMayXucTac; i++) {
        MayXucTac mayXucTac(10); // Đơn giá hóa chất là 10.000 đồng/g

        mayXucTac.nhap(); // Nhập thông tin cho máy xúc tác

        tongChiPhiThue += mayXucTac.tinhChiPhiThue();
        tongChiPhiSuDung += mayXucTac.tinhChiPhiSuDung();
        tongLuongNuocLocDuoc += mayXucTac.tinhLuongNuoc();
    }

    cout << "Tong chi phi thue: " << tongChiPhiThue << endl;
    cout << "Tong chi phi su dung: " << tongChiPhiSuDung << endl;
    cout << "Tong luong nuoc loc duoc: " << tongLuongNuocLocDuoc << endl;

    return 0;
}
