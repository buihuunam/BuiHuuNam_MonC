#include <iostream>
using namespace std;

class MayXucTac {
public:
    static const int DON_GIA_THUE = 80000; // Đơn giá thuê máy
    static const int DON_GIA_HOA_CHAT = 10000; // Đơn giá hóa chất/g

    MayXucTac() {
        cong_suat_loc = 0;
        thoi_gian_su_dung = 0;
        luong_hoa_chat = 0;
    }

    void nhap() {
        cout << "Nhap cong suat loc (m3/h): ";
        cin >> cong_suat_loc;
        cout << "Nhap thoi gian su dung (h): ";
        cin >> thoi_gian_su_dung;
        cout << "Nhap luong hoa chat (g): ";
        cin >> luong_hoa_chat;
    }

    float tinhCongSuatThucTe() {
        if (thoi_gian_su_dung < 10) {
            return cong_suat_loc * (luong_hoa_chat / 100);
        } else {
            return cong_suat_loc * (luong_hoa_chat / 100) / (thoi_gian_su_dung / 10);
        }
    }

    float tinhChiPhiThue() {
        return DON_GIA_THUE * thoi_gian_su_dung;
    }

    float tinhChiPhiSuDung() {
        float cong_suat_thuc_te = tinhCongSuatThucTe();
        float luong_nuoc = cong_suat_thuc_te * thoi_gian_su_dung;
        float chi_phi_thue = tinhChiPhiThue();
        return chi_phi_thue + luong_nuoc * DON_GIA_HOA_CHAT;
    }

    float tinhLuongNuoc() {
        return tinhCongSuatThucTe() * thoi_gian_su_dung;
    }

    // Hàm tinhChiPhi để phản ánh yêu cầu của bạn
    float tinhChiPhi() {
        return tinhChiPhiSuDung();
    }

private:
    float cong_suat_loc; // Công suất lọc (m3/h)
    float thoi_gian_su_dung; // Thời gian sử dụng (h)
    float luong_hoa_chat; // Lượng hóa chất (g)
};

void main() {
    cout << "Don gia hoa chat: " << MayXucTac::DON_GIA_HOA_CHAT << endl;
    MayXucTac m;
    m.nhap(); // Nhập thông tin sử dụng của máy xúc tác này
    cout << "Chi phi su dung may: " << m.tinhChiPhi() << endl;
    cout << "Luong nuoc loc duoc: " << m.tinhLuongNuoc() << endl;
}
