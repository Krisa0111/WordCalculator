#include "WordCounter.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>


//Teszt szavak lesznek itt
// OK __alma__ _123_ 12_3
//NOK :_:_:  112asf*  /_  \_ 12\ @3 @_ -. :-

using namespace std;

void WordCounter::count(ifstream& file) {
    
    while (file >> word) {
        word.erase(remove_if(word.begin(), word.end(), [](char c) { return !isalnum(c) && c != '_'; }), word.end());
        transform(word.begin(), word.end(), word.begin(), [](char c) { return tolower(c); });
        if (!word.empty()) {
            ++wordCount[word];
        }
    }
}

void WordCounter::sortAndPrintByAppearance(ofstream& file) {
    vector<pair<string, int>> sortedByAppearance(wordCount.begin(), wordCount.end());
    sort(sortedByAppearance.begin(), sortedByAppearance.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
        });
    file << left << setw(50) << "Word" << setw(50) << "Count" << endl;
    file << setfill('-') << setw(100) << "-" << endl;
    file << setfill(' ');
    for (const auto& [word, count] : sortedByAppearance) {
        file << left << setw(50) << word << setw(50) << count << endl;
    }
}
void WordCounter::sortAndPrintAlphabetically(ofstream& file) {
    vector<string> sortedAlphabetically;
    for (const auto& [word, count] : wordCount) {
        sortedAlphabetically.push_back(word);
    }
    sort(sortedAlphabetically.begin(), sortedAlphabetically.end());
    file << left << setw(50) << "Word" << setw(50) << "Count" << endl;
    file << setfill('-') << setw(100) << "-" << endl;
    file << setfill(' ');
    for (const auto& word : sortedAlphabetically) {
        file << left << setw(50) << word << setw(50) << wordCount[word] << endl;
    }
}
