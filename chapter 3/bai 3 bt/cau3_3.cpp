#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    float score1, score2, score3, score4, score5;
    float average;
    cout << "nhap diem thu 1:" << endl;
    cin >> score1;
    cout << "nhap diem thu 2:" << endl;
    cin >> score2;
    cout << "nhap diem thu 3:" << endl;
    cin >> score3;
    cout << "nhap diem thu 4:" << endl;
    cin >> score4;
    cout << "nhap diem thu 5:" << endl;
    cin >> score5;
    average = score1 + score2 + score3 + score4 + score5;
    cout << setprecision(1) << fixed << "diem trung binh la " << average << endl;
    return 0;
}