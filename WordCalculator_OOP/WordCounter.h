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
   
    WordCounter() {};

    void count(ifstream& file);

    void sortAndPrintByAppearance(ofstream& file);

    void sortAndPrintAlphabetically(ofstream& file);

private:
    string word;
    mutable map<string, int> wordCount;

};

