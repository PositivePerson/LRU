#include <bits/stdc++.h>
#include <iterator>
#include "displayers.h"
#include "findLeast.h"
#include "generator.h"

using namespace std;

int main()
{
    int fault = 0;
    int pageHit = 0;

    int capacity = 3;
    cout << "Storage capacity (number): ";
    cin >> capacity;
    vector<int> storage(capacity, -1);
    vector<int> storageOrder(capacity, -1);
    int order = 0;

    vector<int> pages = { 7, 9, 1, 2, 9, 3, 9, 4, 2, 3, 9, 3, 2 };
//    int pagesAmount = 3;
//    cout << "Pages amount (number): ";
//    cin >> pagesAmount;
//    cout << '\n';
//    cout << "----- generators -----\n";
//    vector<int> pages = generatePages(pagesAmount);
//    vector<pair<int, bool>> removedPages = generateRemoved(pages);
//    cout << "--- end of generators ---\n";

    for(auto page: pages){
        cout << '\n';
        displayStorage(storage);
        cout << '\n';

        cout  << "Page " << page << '\n';

        bool alreadyInStorage = false;
        for(int i=0 ; i<storage.size() ; i++) {
            if(storage[i] == page ) {
                alreadyInStorage = true;
                break;
            }
        }

        if(alreadyInStorage) {
            cout << "Already in Storage...\n";
            pageHit++;

            for(int j=0 ; j<storage.size() ; j++) {
                if(storage[j] == page) {
//                    cout << "Removing first instance of " << page << " that was at index " << j << '\n';
//                    storage.erase(storage.begin() + j);

                    cout << "Updating order of page " << page << '\n';
                    storageOrder[j] = order++;
                }
            }
        } else {
            cout << "New in Storage...\n";
            fault++;

            int leastRecentStorageIndex = 0;
            int min = storageOrder[0];
            for(int j=0 ; j<storage.size() ; j++) {
                if(storageOrder[j] < min) {
//                    cout << "Removing first instance of " << page << " that was at index " << j << '\n';
//                    storage.erase(storage.begin() + j);
                    leastRecentStorageIndex = j;
                        min = storageOrder[j];
                }
            }

            storage[leastRecentStorageIndex] = page;
            storageOrder[leastRecentStorageIndex] = order++;
        }
//        storage.push_back(page);

//        if(storage.size() > capacity) {
//            storage.erase(storage.begin());
//        }
    }

    cout << '\n';
    displayStorage(storage);
    cout << '\n';

    cout << '\n';
    cout << "Page Faults = " << fault << '\n';
    cout << "Page Hits = " << pageHit << '\n';
    return 0;
}