#include <iostream>
#include <string>

// Sử dụng namespace std để ngắn gọn hóa việc sử dụng các thành phần của nó
using namespace std;

// Định nghĩa cấu trúc MovieData
struct MovieData {
    string title;          // Tiêu đề phim
    string director;       // Đạo diễn
    int yearReleased;      // Năm phát hành
    int runningTime;       // Thời lượng (đơn vị: phút)
    double productionCost; // Chi phí sản xuất
    double firstYearRevenue; // Doanh thu năm đầu tiên
};

// Hàm để hiển thị thông tin về phim, bao gồm cả doanh thu/lỗ năm đầu tiên
void hienThiThongTinPhim(const MovieData& phim) {
    cout << "Tiêu đề: " << phim.title << endl;
    cout << "Đạo diễn: " << phim.director << endl;
    cout << "Năm phát hành: " << phim.yearReleased << endl;
    cout << "Thời lượng: " << phim.runningTime << " phút" << endl;
    cout << "Chi phí sản xuất: $" << phim.productionCost << endl;
    cout << "Doanh thu/lỗ năm đầu tiên: $" << (phim.firstYearRevenue - phim.productionCost) << endl;
    cout << endl;
}

int main() {
    // Tạo hai biến MovieData và khởi tạo giá trị cho thành viên của chúng
    MovieData phim1 = {"Inception", "Christopher Nolan", 2010, 148, 160000000, 825500000};
    MovieData phim2 = {"The Shawshank Redemption", "Frank Darabont", 1994, 142, 25000000, 58900000};

    // Hiển thị thông tin về phim đầu tiên
    cout << "Thông tin về Phim 1:" << endl;
    hienThiThongTinPhim(phim1);

    // Hiển thị thông tin về phim thứ hai
    cout << "Thông tin về Phim 2:" << endl;
    hienThiThongTinPhim(phim2);

    return 0;
}
