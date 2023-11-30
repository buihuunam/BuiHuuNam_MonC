#include <iostream>
using namespace std;
int main(){
    //khai bao bien thoi gian va quang duong
    float speed,distance;
    int hour;
    //nhap thoi gian va toc do
    cout << "nhap thoi gian: " << endl;
    cin >> hour;
    cout << "nhap toc do: " << endl;
    cin >> speed;
    //neu thoi gian nho hon 1 thi nhap lai
    while(hour < 1){
        cout << "press again: ";
        cin >> hour;
    }
    //trang tri bang
    cout << "hour" << "\t" << "distance" << endl;
    //xuat ra bang gia tri quang duong
    for(int i = 1; i <= hour; ++i){
        distance =  i * speed;
        cout << i << "\t" << distance << endl;
    }
    return 0;
}