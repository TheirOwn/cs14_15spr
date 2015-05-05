//Name: Nicholas Rogers
//SSID: 861152009
//Date: 4/27/15
#ifndef LAB4_H
#define LAB4_H
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void preOrder(int m, int n, int x) {
    if(m + n > x) { return; }
    cout << m << ' ' << n << endl;
    preOrder(2*m - n, m, x);
    preOrder(2*m + n, m, x);
    preOrder(m + 2*n, n, x);
}

void preOrder(int x) {
    preOrder(2,1, x);
    preOrder(3,1, x);
}

void postOrder(int m, int n, int x) {
    if(m + n > x) { return; }
    postOrder(2*m - n, m, x);
    postOrder(2*m + n, m, x);
    postOrder(m + 2*n, n, x);
    cout << m << ' ' << n << endl;
}

void postOrder(int x) {
    postOrder(2,1, x);
    postOrder(3,1, x);
}

priority_queue<int> that;
vector<int> superX;
vector<int> superY;

void sorted(int m, int n, int x) {
    if(m + n > x) { return; }
    that.push(m + n);
    superX.push_back(m);
    superY.push_back(n);
    
    sorted(2*m - n, m, x);
    sorted(2*m + n, m, x);
    sorted(m + 2*n, n, x);
}


void sorted(int x) {
    while(!that.empty()) { that.pop();}
    superX.clear();
    superY.clear();
    
    sorted(2, 1, x);
    sorted(3, 1, x);
    
    stack<int> sorter;
    while(!that.empty()) {
        sorter.push(that.top());
        that.pop();
    }
    
    while(!sorter.empty()) {
        for(unsigned i = 0; i < superX.size(); i++) {
            if(sorter.top() == superX.at(i) + superY.at(i)) {
                cout << superX.at(i) << ' ' << superY.at(i) << endl;
                superX.at(i) = -1;
                superY.at(i) = -1;
                break;
            }
        }
        sorter.pop();
    }
    
}

#endif
