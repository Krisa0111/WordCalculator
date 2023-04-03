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

    ofstream countByAppearance("countByAppearance_OOP.txt");
    ofstream countByAlphabet("countByAlphabet_OOP.txt");

    wc.sortAndPrintByAppearance(countByAppearance);

    wc.sortAndPrintAlphabetically(countByAlphabet);

    countByAppearance.close();
    countByAlphabet.close();
}