// WordCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // f�jl megnyit�sa
    ifstream file("file.cpp");

    // map l�trehoz�sa
    map<string, int> wordCount;

    // f�jl beolvas�sa szavank�nt
    string word;
    while (file >> word) {
        // nem valid szavak kikuk�z�sa
        word.erase(remove_if(word.begin(), word.end(), [](char c) { return !isalnum(c) && c != '_'; }), word.end());
        // mindent kisbet�re
        transform(word.begin(), word.end(), word.begin(), [](char c) { return tolower(c); });
        if (!word.empty()) {
            ++wordCount[word];
        }
    }

    // f�jl becsuk
    file.close();

    // output f�jlok
    ofstream countByAppearance("countByAppearance.txt");
    ofstream countByAlphabet("countByAlphabet.txt");

    // rendez�s gyakoris�g szerint
    vector<pair<string, int>> sortedByAppearance(wordCount.begin(), wordCount.end());
    sort(sortedByAppearance.begin(), sortedByAppearance.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
        });
    for (const auto& [word, count] : sortedByAppearance) {
        countByAppearance << word << ": " << count << endl;
    }

    // rendez�s abc sorrendben
    vector<string> sortedAlphabetically;
    for (const auto& [word, count] : wordCount) {
        sortedAlphabetically.push_back(word);
    }
    sort(sortedAlphabetically.begin(), sortedAlphabetically.end());
    for (const auto& word : sortedAlphabetically) {
        countByAlphabet << word << ": " << wordCount[word] << endl;
    }

    // output f�jlok bez�r�sa
    countByAppearance.close();
    countByAlphabet.close();

}
