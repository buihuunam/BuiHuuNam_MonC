#include <iostream>
#include <string>

using namespace std;

// Định nghĩa cấu trúc cho ngân sách hàng tháng
struct MonthlyBudget {
    double housing;
    double utilities;
    double householdExpenses;
    double transportation;
    double food;
    double medical;
    double insurance;
    double entertainment;
    double clothing;
    double miscellaneous;
};

// Hàm nhập số tiền đã chi trả cho từng mục ngân sách
void nhapSoTienChi(MonthlyBudget& nganSach) {
    cout << "Nhập số tiền đã chi trả cho mỗi mục ngân sách hàng tháng:" << endl;
    cout << "Housing: $";
    cin >> nganSach.housing;
    cout << "Utilities: $";
    cin >> nganSach.utilities;
    cout << "Household Expenses: $";
    cin >> nganSach.householdExpenses;
    cout << "Transportation: $";
    cin >> nganSach.transportation;
    cout << "Food: $";
    cin >> nganSach.food;
    cout << "Medical: $";
    cin >> nganSach.medical;
    cout << "Insurance: $";
    cin >> nganSach.insurance;
    cout << "Entertainment: $";
    cin >> nganSach.entertainment;
    cout << "Clothing: $";
    cin >> nganSach.clothing;
    cout << "Miscellaneous: $";
    cin >> nganSach.miscellaneous;
}

// Hàm hiển thị báo cáo về số tiền dư hoặc thiếu trong từng mục và tổng ngân sách hàng tháng
void hienThiBaoCao(const MonthlyBudget& nganSachThucTe, const MonthlyBudget& nganSachDuKien) {
    cout << "\nBáo cáo về ngân sách hàng tháng:" << endl;

    // Tính toán số tiền dư hoặc thiếu cho từng mục
    double duKienTotal = nganSachDuKien.housing + nganSachDuKien.utilities +
                         nganSachDuKien.householdExpenses + nganSachDuKien.transportation +
                         nganSachDuKien.food + nganSachDuKien.medical + nganSachDuKien.insurance +
                         nganSachDuKien.entertainment + nganSachDuKien.clothing +
                         nganSachDuKien.miscellaneous;

    double thucTeTotal = nganSachThucTe.housing + nganSachThucTe.utilities +
                         nganSachThucTe.householdExpenses + nganSachThucTe.transportation +
                         nganSachThucTe.food + nganSachThucTe.medical + nganSachThucTe.insurance +
                         nganSachThucTe.entertainment + nganSachThucTe.clothing +
                         nganSachThucTe.miscellaneous;

    // Hiển thị số tiền dư hoặc thiếu cho từng mục
    cout << "Housing: $" << nganSachThucTe.housing - nganSachDuKien.housing << endl;
    cout << "Utilities: $" << nganSachThucTe.utilities - nganSachDuKien.utilities << endl;
    cout << "Household Expenses: $" << nganSachThucTe.householdExpenses - nganSachDuKien.householdExpenses << endl;
    cout << "Transportation: $" << nganSachThucTe.transportation - nganSachDuKien.transportation << endl;
    cout << "Food: $" << nganSachThucTe.food - nganSachDuKien.food << endl;
    cout << "Medical: $" << nganSachThucTe.medical - nganSachDuKien.medical << endl;
    cout << "Insurance: $" << nganSachThucTe.insurance - nganSachDuKien.insurance << endl;
    cout << "Entertainment: $" << nganSachThucTe.entertainment - nganSachDuKien.entertainment << endl;
    cout << "Clothing: $" << nganSachThucTe.clothing - nganSachDuKien.clothing << endl;
    cout << "Miscellaneous: $" << nganSachThucTe.miscellaneous - nganSachDuKien.miscellaneous << endl;

    // Hiển thị tổng số tiền dư hoặc thiếu cho toàn bộ ngân sách hàng tháng
    cout << "\nTổng số tiền dư hoặc thiếu cho ngân sách hàng tháng: $"
         << thucTeTotal - duKienTotal << endl;
}

int main() {
    // Ngân sách dự kiến
    MonthlyBudget nganSachDuKien = {500.00, 150.00, 65.00, 50.00, 250.00,
                                     30.00, 100.00, 150.00, 75.00, 50.00};

    // Ngân sách thực tế
    MonthlyBudget nganSachThucTe;

    // Nhập số tiền đã chi trả cho từng mục ngân sách
    nhapSoTienChi(nganSachThucTe);

    // Hiển thị báo cáo về số tiền dư hoặc thiếu
    hienThiBaoCao(nganSachThucTe, nganSachDuKien);

    return 0;
}
