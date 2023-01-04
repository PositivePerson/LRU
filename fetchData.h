//
// Created by Bartek on 04/01/2023.
//

#ifndef LRU_FETCHDATA_H
#define LRU_FETCHDATA_H

#include "iostream"
#include <bits/stdc++.h>

using namespace std;

void getPagesFromFile(vector<int> &pages) {
    string line;
    ifstream sourcefile ("../pages_LRU.txt");
    if (sourcefile.is_open())
    {
        cout << "Retrieving data from file: \n";
        while ( getline (sourcefile,line) )
        {
            cout << line << '\n';
            pages.push_back(stoi(line));
        }
        sourcefile.close();
    }
    else cout << "Error: Unable to open data source file!\n";
}

#endif //LRU_FETCHDATA_H
