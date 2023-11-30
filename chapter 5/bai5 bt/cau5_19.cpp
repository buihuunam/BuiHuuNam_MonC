#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main(){
    double budget,cost,total;
    string expense;
    cout << "nhap khoan chi phi du phong: ";
    cin >> budget;
    //nhap chi phi khi nao het thi bam end se nhan ket qua
    while(expense != "end"){
        cout << "nhap chi phi:" << endl;
        cin >> expense;
        if(expense != "end"){
        cout << "nhap gia: \t" << endl;
        cin >> cost;
        total += cost;
        }
    } 
    //kiem tra ngan sach co vuot qua khong
    if(total > budget){
        cout << "vuot qua chi phi!";
    } else 
    if(total == budget)
    {
        cout << "vua du!";
    } else
    {
        cout << "duoi muc chi phi du phong!";
    }
    return 0;
}