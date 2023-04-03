// WordCalculator_OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "WordCounter.h"

int main() {
    // fájl kinyit
    ifstream file("WordCounter.cpp");

    WordCounter wc;

    // szavak megszámolása
    wc.count(file);

    // fájl becsuk
    file.close();

    ofstream countByAppearance("countByAppearance.txt");
    ofstream countByAlphabet("countByAlphabet.txt");

    wc.sortAndPrintByAppearance(countByAppearance);

    wc.sortAndPrintAlphabetically(countByAlphabet);

    // Close output files
    countByAppearance.close();
    countByAlphabet.close();
}