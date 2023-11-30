#include <iostream>
#include <cstdlib> // Thư viện để sử dụng hàm rand
#include <ctime>   // Thư viện để sử dụng hàm time
using namespace std;

// Hàm để lấy lựa chọn từ người chơi
int getPlayerChoice() {
    cout << "Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ";
    int choice;
    cin >> choice;
    return choice;
}

// Hàm để lấy lựa chọn ngẫu nhiên từ máy tính
int getComputerChoice() {
    return rand() % 3 + 1; // Sinh số ngẫu nhiên trong khoảng từ 1 đến 3
}

// Hàm để hiển thị lựa chọn thành chữ (Rock, Paper, Scissors)
string choiceToString(int choice) {
    if (choice == 1) {
        return "Rock";
    } else if (choice == 2) {
        return "Paper";
    } else {
        return "Scissors";
    }
}

// Hàm để xác định người chơi nào là người thắng cuộc
int determineWinner(int playerChoice, int computerChoice) {
    if (playerChoice == computerChoice) {
        return 0; // Hòa
    } else if ((playerChoice == 1 && computerChoice == 3) ||
               (playerChoice == 2 && computerChoice == 1) ||
               (playerChoice == 3 && computerChoice == 2)) {
        return 1; // Người chơi thắng
    } else {
        return -1; // Máy tính thắng
    }
}

int main() {
    srand(time(0)); // Khởi tạo seed cho hàm rand

    // Lặp cho đến khi có một người chơi thắng
    do {
        int playerChoice = getPlayerChoice();
        int computerChoice = getComputerChoice();

        cout << "Computer chose: " << choiceToString(computerChoice) << endl;

        int result = determineWinner(playerChoice, computerChoice);

        if (result == 0) {
            cout << "It's a tie! Let's play again." << endl;
        } else if (result == 1) {
            cout << "Congratulations! You win!" << endl;
        } else {
            cout << "Sorry, you lose. Try again!" << endl;
        }

    } while (result == 0);

    return 0;
}
