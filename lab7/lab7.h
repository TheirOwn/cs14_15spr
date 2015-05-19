#include <iostream>
#include <vector> 
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void test() {
    vector<string> wordlist;
    fstream fin("words.txt");
    if(!fin.is_open()) {
        cout << "error opening words.txt." << endl;
        return;
    }
    string str;
    while (!fin.eof()) {
        fin >> str;
        wordlist.push_back(str);
    }
    fin.close();
    fin.open("data.txt");
    if(!fin.is_open()) {
        cout << "error opening data.txt." << endl;
        return;
    }
    //Hash
    unordered_set<string> hash;

    //tree
    set<string> tree;
    
    double treeTimes[20];           //evens to insert odds to find
    double hashTimes[20];
    for(int max = 5000; max <= 50000; max += 5000) {
        for(int i = 0; i < 20; i += 2){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            for(int n = 0; n < max; n++) {
                tree.insert(wordlist.at(n));
            }
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

            treeTimes[i] = (time_span.count() * 1000) / max;
            
            t1 = high_resolution_clock::now();
            for(int n = 0; n < max; n++) {
                hash.insert(wordlist.at(n));
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            hashTimes[i] = (time_span.count() * 1000) / max;
        }
        for(int i = 1; i < 20; i += 2) {
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            for(int n = 0; n < max; n++) {
                tree.find(wordlist.at(n));
            }
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

            treeTimes[i] = (time_span.count() * 1000) / max;

            t1 = high_resolution_clock::now();
            for(int n = 0; n < max; n++) {
                hash.find(wordlist.at(n));
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            hashTimes[i] = (time_span.count() * 1000) / max;

            
        }
        for(int i = 2; i < 20; i += 2) {        //evens (to insert)
            treeTimes[0] += treeTimes[i];
            hashTimes[0] += hashTimes[i];
            treeTimes[1] += treeTimes[i + 1];
            hashTimes[1] += hashTimes[i + 1];
        }
        treeTimes[0] /= 10;         //insert
        treeTimes[1] /= 10;
        hashTimes[0] /= 10;         //find
        hashTimes[1] /= 10;
        
        fin << max << ' ' << treeTimes[0] << ' ' << hashTimes[0] << ' ' << treeTimes[1] << ' ' << hashTimes[1] << endl;
        
        random_shuffle ( wordlist.begin(), wordlist.end() );
    }
    fin.close();
}