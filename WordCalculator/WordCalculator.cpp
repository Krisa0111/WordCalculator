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
    // fájl megnyitása
    ifstream file("file.cpp");

    // map létrehozása
    map<string, int> wordCount;

    // fájl beolvasása szavanként
    string word;
    while (file >> word) {
        // nem valid szavak kikukázása
        word.erase(remove_if(word.begin(), word.end(), [](char c) { return !isalnum(c) && c != '_'; }), word.end());
        // mindent kisbetûre
        transform(word.begin(), word.end(), word.begin(), [](char c) { return tolower(c); });
        if (!word.empty()) {
            ++wordCount[word];
        }
    }

    // fájl becsuk
    file.close();

    // output fájlok
    ofstream countByAppearance("countByAppearance.txt");
    ofstream countByAlphabet("countByAlphabet.txt");

    // rendezés gyakoriság szerint
    vector<pair<string, int>> sortedByAppearance(wordCount.begin(), wordCount.end());
    sort(sortedByAppearance.begin(), sortedByAppearance.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
        });
    for (const auto& [word, count] : sortedByAppearance) {
        countByAppearance << word << ": " << count << endl;
    }

    // rendezés abc sorrendben
    vector<string> sortedAlphabetically;
    for (const auto& [word, count] : wordCount) {
        sortedAlphabetically.push_back(word);
    }
    sort(sortedAlphabetically.begin(), sortedAlphabetically.end());
    for (const auto& word : sortedAlphabetically) {
        countByAlphabet << word << ": " << wordCount[word] << endl;
    }

    // output fájlok bezárása
    countByAppearance.close();
    countByAlphabet.close();

}
