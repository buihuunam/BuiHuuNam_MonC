#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Function to convert a word to Pig Latin
string convertToPigLatin(const string& word) {
    if (word.empty()) {
        return "";
    }

    // Move the first letter to the end and append "ay"
    return word.substr(1) + word[0] + "ay";
}

// Function to convert a sentence to Pig Latin
string convertSentenceToPigLatin(const string& sentence) {
    stringstream ss(sentence);
    string word;
    vector<string> pigLatinWords;

    // Process each word in the sentence
    while (ss >> word) {
        pigLatinWords.push_back(convertToPigLatin(word));
    }

    // Combine the Pig Latin words into a sentence
    string pigLatinSentence;
    for (const string& pigLatinWord : pigLatinWords) {
        pigLatinSentence += pigLatinWord + " ";
    }

    // Remove the trailing space
    pigLatinSentence.pop_back();

    return pigLatinSentence;
}

int main() {
    string inputSentence;

    // Input a sentence from the user
    cout << "Enter a sentence: ";
    getline(cin, inputSentence);

    // Call the function to convert the sentence to Pig Latin
    string pigLatinSentence = convertSentenceToPigLatin(inputSentence);

    // Display the result
    cout << "Pig Latin: " << pigLatinSentence << endl;

    return 0;
}
