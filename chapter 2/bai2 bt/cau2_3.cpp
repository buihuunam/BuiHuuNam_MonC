#include <iostream>

using namespace std;

int main() {
    // Constants for sales tax rates
    const double stateTaxRate = 0.04;  // 4%
    const double countyTaxRate = 0.02; // 2%

    // Purchase amount
    double purchaseAmount = 95.0;

    // Calculate state sales tax
    double stateSalesTax = purchaseAmount * stateTaxRate;

    // Calculate county sales tax
    double countySalesTax = purchaseAmount * countyTaxRate;

    // Calculate total sales tax
    double totalSalesTax = stateSalesTax + countySalesTax;

    // Display the result
    cout << "The state sales tax is $" << stateSalesTax << endl;
    cout << "The county sales tax is $" << countySalesTax << endl;
    cout << "The total sales tax on a $" << purchaseAmount << " purchase is $" << totalSalesTax << endl;

    return 0;
}
