#include <iostream>
#include <cctype> // For isalpha function

using namespace std;

// Function to count the number of vowels in a C-string
int countVowels(const char* str) {
    int vowelCount = 0;

    // Duyệt qua chuỗi để đếm số lượng nguyên âm
    while (*str != '\0') {
        if (isalpha(*str)) {
            char lowercaseChar = tolower(*str);

            // Kiểm tra xem ký tự có phải là nguyên âm hay không
            if (lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' ||
                lowercaseChar == 'o' || lowercaseChar == 'u') {
                vowelCount++;
            }
        }

        str++;
    }

    return vowelCount;
}

// Function to count the number of consonants in a C-string
int countConsonants(const char* str) {
    int consonantCount = 0;

    // Duyệt qua chuỗi để đếm số lượng phụ âm
    while (*str != '\0') {
        if (isalpha(*str)) {
            char lowercaseChar = tolower(*str);

            // Kiểm tra xem ký tự có phải là phụ âm hay không
            if (!(lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' ||
                  lowercaseChar == 'o' || lowercaseChar == 'u')) {
                consonantCount++;
            }
        }

        str++;
    }

    return consonantCount;
}

int main() {
    const int MAX_SIZE = 1000;
    char inputString[MAX_SIZE];

    // Menu
    char choice;
    do {
        cout << "Enter a string: ";
        cin.getline(inputString, MAX_SIZE);

        cout << "Menu:\n";
        cout << "A) Count the number of vowels in the string\n";
        cout << "B) Count the number of consonants in the string\n";
        cout << "C) Count both the vowels and consonants in the string\n";
        cout << "D) Enter another string\n";
        cout << "E) Exit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'A':
            case 'a':
                cout << "Number of vowels: " << countVowels(inputString) << endl;
                break;
            case 'B':
            case 'b':
                cout << "Number of consonants: " << countConsonants(inputString) << endl;
                break;
            case 'C':
            case 'c':
                cout << "Number of vowels: " << countVowels(inputString) << endl;
                cout << "Number of consonants: " << countConsonants(inputString) << endl;
                break;
            case 'D':
            case 'd':
                // Continue to the next iteration of the loop to input another string
                cin.ignore(); // Clear the input buffer
                continue;
            case 'E':
            case 'e':
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 'E' && choice != 'e');

    return 0;
}
