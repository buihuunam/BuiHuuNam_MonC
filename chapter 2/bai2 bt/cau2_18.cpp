#include <iostream>

using namespace std;

int main() {
    // Khai báo và khởi tạo biến
    int totalCustomers = 16500;
    double percentageEnergyDrinkCustomers = 0.15;  // 15%
    double percentageCitrusFlavoredPreference = 0.58;  // 58%

    // Tính số lượng khách hàng mua ít nhất một lon nước tăng lực mỗi tuần
    int energyDrinkCustomers = totalCustomers * percentageEnergyDrinkCustomers;

    // Tính số lượng khách hàng thích nước tăng lực vị cam
    int citrusFlavoredCustomers = energyDrinkCustomers * percentageCitrusFlavoredPreference;

    // Hiển thị kết quả
    cout << "So khach hang khoang " << energyDrinkCustomers << " nguoi mua it nhat mot lon nuoc tang luc moi tuan." << endl;
    cout << "So khach hang khoang " << citrusFlavoredCustomers << " nguoi thich nuoc tang luc vi cam." << endl;

    return 0;
}
