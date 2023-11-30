#include <iostream>
#include <string>
using namespace std;

// Hàm để nhận số lượng tai nạn của một khu vực
int getNumAccidents(string regionName) {
    int accidents;
    cout << "Nhap so tai nan giao thong cua khu vuc " << regionName << " trong nam ngoai: ";
    
    // Nhập và kiểm tra giá trị hợp lệ
    do {
        cin >> accidents;
        if (accidents < 0) {
            cout << "Loi: So tai nan khong the la so am. Nhap lai: ";
        }
    } while (accidents < 0);

    return accidents;
}

// Hàm để xác định khu vực có số lượng tai nạn ít nhất
void findLowest(int north, int south, int east, int west, int central) {
    int lowestAccidents = north;
    string lowestRegion = "North";

    if (south < lowestAccidents) {
        lowestAccidents = south;
        lowestRegion = "South";
    }

    if (east < lowestAccidents) {
        lowestAccidents = east;
        lowestRegion = "East";
    }

    if (west < lowestAccidents) {
        lowestAccidents = west;
        lowestRegion = "West";
    }

    if (central < lowestAccidents) {
        lowestAccidents = central;
        lowestRegion = "Central";
    }

    // Hiển thị thông tin về khu vực có số lượng tai nạn ít nhất
    cout << "Khu vuc co so tai nan it nhat la " << lowestRegion << " voi so tai nan la: " << lowestAccidents << endl;
}

int main() {
    // Gọi hàm để nhận số lượng tai nạn từng khu vực
    int north = getNumAccidents("North");
    int south = getNumAccidents("South");
    int east = getNumAccidents("East");
    int west = getNumAccidents("West");
    int central = getNumAccidents("Central");

    // Gọi hàm để xác định và hiển thị khu vực có số lượng tai nạn ít nhất
    findLowest(north, south, east, west, central);

    return 0;
}
