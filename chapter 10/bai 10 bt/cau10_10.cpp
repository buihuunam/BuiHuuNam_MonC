#include <iostream>
#include <string>

using namespace std;

// Function to replace all occurrences of a substring in a string
string replaceSubstring(const string& str1, const string& str2, const string& str3) {
    string result = str1;
    size_t position = 0;

    // Find and replace all occurrences of str2 in str1
    while ((position = result.find(str2, position)) != string::npos) {
        result.replace(position, str2.length(), str3);
        position += str3.length();
    }

    return result;
}

int main() {
    // Input strings from the user
    string string1, string2, string3;
    
    cout << "Enter the original string: ";
    getline(cin, string1);

    cout << "Enter the substring to replace: ";
    getline(cin, string2);

    cout << "Enter the replacement substring: ";
    getline(cin, string3);

    // Call the function to replace substring
    string result = replaceSubstring(string1, string2, string3);

    // Display the result
    cout << "Modified string: " << result << endl;

    return 0;
}
