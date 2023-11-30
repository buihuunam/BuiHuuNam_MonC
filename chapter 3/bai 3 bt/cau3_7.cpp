#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    // Constants for ticket prices and revenue share
    const double ADULTTICKETPRICE = 10.00;
    const double CHILDTICKETPRICE = 6.00;
    const double DISTRIBUTORSHAREPERCENTAGE = 0.2;  // 20% to the distributor

    // Variables to store user input
    string movieName;
    int adultTicketsSold, childTicketsSold;

    // Prompt the user to enter movie details and ticket sales
    cout << "Enter the name of the movie: ";
    getline(cin, movieName);
    cout << "Enter the number of adult tickets sold: ";
    cin >> adultTicketsSold;
    cout << "Enter the number of child tickets sold: ";
    cin >> childTicketsSold;

    // Calculate the gross and net box office profit
    double grossProfit = (adultTicketsSold * ADULTTICKETPRICE) + (childTicketsSold * CHILDTICKETPRICE);
    double distributorShare = grossProfit * DISTRIBUTORSHAREPERCENTAGE;
    double netProfit = grossProfit - distributorShare;

    // Display the results
    cout << "Movie Name: \"" << movieName << "\"" << endl;
    cout << "Adult Tickets Sold: " << adultTicketsSold << endl;
    cout << "Child Tickets Sold: " << childTicketsSold << endl;
    cout << fixed << setprecision(2);
    cout << "Gross Box Office Profit: $" << grossProfit << endl;
    cout << "Net Box Office Profit: $" << netProfit << endl;
    cout << "Amount Paid to Distributor: $" << distributorShare << endl;

    return 0;
}
