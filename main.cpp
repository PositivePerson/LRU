#include <bits/stdc++.h>
#include "displayers.h"
#include "generator.h"
#include "fetchData.h"

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



//    vector<int> pages = { 7, 9, 1, 2, 9, 3, 9, 4, 2, 3, 9, 3, 2 };
// ---------- OR ----------
//        int pagesAmount = 3;
//        cout << "Pages amount (number): ";
//        cin >> pagesAmount;
//        cout << '\n';
//        cout << "----- generator -----\n";
//        vector<int> pages = generatePages(pagesAmount);
//        cout << "--- end of generator ---\n";
// ---------- OR ----------
    vector<int> pages;
    cout << '\n';
    getPagesFromFile(pages);



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
                    leastRecentStorageIndex = j;
                        min = storageOrder[j];
                }
            }

            storage[leastRecentStorageIndex] = page;
            storageOrder[leastRecentStorageIndex] = order++;
        }
    }

    cout << '\n';
    displayStorage(storage);
    cout << '\n';

    cout << '\n';
    cout << "Page Faults = " << fault << '\n';
    cout << "Page Hits = " << pageHit << '\n';
    return 0;
}