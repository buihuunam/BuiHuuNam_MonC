#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    const float JOINCOST = 2500;
    const float FEE = 0.04;
    const int year = 6;
    float projectrate = JOINCOST;
    cout << "fee\t" << "project rate" << endl;
    //xuất ra bảng giá trị
    for(int i = 1; i <= year; ++i ){
        cout << i << "\t" << projectrate << endl;
        projectrate *= (1 + FEE);
    }
    return 0;
}