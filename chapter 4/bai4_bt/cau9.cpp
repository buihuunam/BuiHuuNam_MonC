#include<iostream>
using namespace std;
int main(){
    //nhập giá
    double pennies, nickels, dimes, quarters, sum;
    cout << "press prices of pennies: ";
    cin >> pennies;
    cout << "press prices of nickels: ";
    cin >> nickels;
    cout << "press prices of dimes: ";
    cin >> dimes;
    cout << "press prices of quarters: ";
    cin >> quarters;
    //tính tổng
    sum = pennies + nickels + dimes + quarters;
    //nếu tổng là 1 thì chúc mừng
    if(sum == 1){
        cout << "congratulate";
    }
    //khác 1 thì sẽ hiện nhiều hay ít hơn 1$
    else{
        if(sum < 1){
            cout << "less than 1$";//nếu ít hơn 1$ thì sẽ hiện dòng này
        }
        else if(sum > 1){
            cout << "more than 1$";//nếu nhiều hơn 1$ thì sẽ hiện dòng này
        }
    }
    return 0;
}