#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int classA, classB, classC;
    const double SEATA = 15.00, SEATB = 12.00, SEATC = 9.00;
    double income;
    cout << "nhap so ghe o day A: " << endl;
    cin >> classA;
    cout << "nhap so ghe o day B: " << endl;
    cin >> classB;
    cout << "nhap so ghe o day C: " << endl;
    cin >> classC;
    income = classA * SEATA + classB * SEATB + classC * SEATC;
    cout << setprecision(2) << fixed << "so tien thu duoc tu ban ve la " << income << endl;
    return 0;
}