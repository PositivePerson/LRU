//
// Created by Bartek on 03/01/2023.
//

#ifndef LRU_DISPLAYERS_H
#define LRU_DISPLAYERS_H

#include "iostream"
#include <bits/stdc++.h>

using namespace std;

void displayStorage(vector<int> storage) {
    cout << "Storage is: ";
    for(int i=0; i<storage.size() ; i++) {
        cout << storage[i] << ' ';
    }
    cout << '\n';
}

#endif //LRU_DISPLAYERS_H
