#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class WordCounter {
public:
   
    WordCounter() : letters(0), nums(0), puncts(0), spaces(0), words(0), lines(0) {}

    void count(ifstream& file);

    void sortAndPrintByAppearance(ofstream& file);

    void sortAndPrintAlphabetically(ofstream& file);

private:
    string word;
    mutable map<string, int> wordCount;
    int letters;
    int nums;
    int puncts;
    int spaces;
    int words;
    int lines;
};

