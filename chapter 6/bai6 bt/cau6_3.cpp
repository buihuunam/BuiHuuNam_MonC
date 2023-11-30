#include <iostream>
#include <string>
using namespace std;

// Hàm để nhận doanh số bán hàng của một phòng ban
double getSales(string divisionName) {
    double sales;
    cout << "Nhap doanh so ban hang cua phong ban " << divisionName << ": $";
    
    // Nhập và kiểm tra giá trị hợp lệ
    do {
        cin >> sales;
        if (sales < 0.0) {
            cout << "Loi: Doanh so ban hang khong the la so am. Nhap lai: $";
        }
    } while (sales < 0.0);

    return sales;
}

// Hàm để xác định phòng ban có doanh số bán hàng cao nhất
void findHighest(double neSales, double seSales, double nwSales, double swSales) {
    double highestSales = neSales;
    string highestDivision = "Northeast";

    if (seSales > highestSales) {
        highestSales = seSales;
        highestDivision = "Southeast";
    }

    if (nwSales > highestSales) {
        highestSales = nwSales;
        highestDivision = "Northwest";
    }

    if (swSales > highestSales) {
        highestSales = swSales;
        highestDivision = "Southwest";
    }

    // Hiển thị thông tin về phòng ban có doanh số cao nhất
    cout << "Phong ban co doanh so cao nhat la " << highestDivision << " voi doanh so la: $" << highestSales << endl;
}

int main() {
    // Gọi hàm để nhận doanh số từng phòng ban
    double neSales = getSales("Northeast");
    double seSales = getSales("Southeast");
    double nwSales = getSales("Northwest");
    double swSales = getSales("Southwest");

    // Gọi hàm để xác định và hiển thị phòng ban có doanh số cao nhất
    findHighest(neSales, seSales, nwSales, swSales);

    return 0;
}
