#include <iostream>
using namespace std;
int main(){
    float employee, grosspay, statetax, federaltax, FICA;
    //yeu cau nguoi dung nhap so nhan vien
    cout << "press employee number: " << endl;
    cin >> employee;
    //neu nhan vien khac 0 thi tiep tuc nhap 
    if(employee != 0){
        cout << "press gross pay: " << endl;
        cin >> grosspay;
        cout << "press state tax: " << endl;
        cin >> statetax;
        cout << "press federal tax: " << endl;
        cin >> federaltax;
        cout << "press FICA with-holding: " << endl;
        cin >> FICA;
        //neu statetax + federaltax + FICA > grosspay thi nhap lai
        while(statetax + federaltax + FICA > grosspay){
        cout << "print an error message and reenter the data for that employee! " << endl;
        cout << "press gross pay: " << endl;
        cin >> grosspay;
        cout << "press state tax: " << endl;
        cin >> statetax;
        cout << "press federal tax: " << endl;
        cin >> federaltax;
        cout << "press FICA with-holding: " << endl;
        cin >> FICA;
        }
        cout << "gross pay is " << grosspay << endl;
        cout << "state tax is " << statetax << endl;
        cout << "federal tax is " << federaltax << endl;
        cout << "FICA with-holding is " << FICA << endl;
    }
    return 0;
}