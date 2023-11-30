#include<iostream>
using namespace std;
int main(){
    double gallonOfgas, distance;
    double milePergallon;
    cout << "nhap luong gas tieu thu " << endl;
    cin >> gallonOfgas;
    cout << "nhap quang duong di duoc " << endl;
    cin >> distance;   
    milePergallon = distance / gallonOfgas;
    cout << "quang duong di duoc trong 1 gallon la " << milePergallon << endl;
    return 0;
}