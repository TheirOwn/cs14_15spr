//Name: Nicholas Rogers
//SSID: 861152009
//Date: 4/27/15

#include "lab3.h"

int main() {
    // TwoStackFixed<int> a(6, 3);
    // TwoStackFixed<double> b(6, 3);
    // a.pushStack1(5);
    // a.pushStack1(4);
    // a.pushStack1(3);
    // a.pushStack1(2);
    // cout << "Stack 2: " << endl;
    // a.pushStack2(5);
    // a.pushStack2(4);
    // a.pushStack2(3);
    // a.pushStack2(2);
    // cout << "Pop" << endl;
    // a.popStack1();
    // a.popStack2();
    // cout << "Push 0" << endl;
    // a.pushStack1(0);
    // a.pushStack2(0);
    // // b.popStack1();
    // // b.popStack2();
    // cout << "Full:" << endl;
    // assert(!a.isEmptyStack1());
    // assert(b.isEmptyStack1());
    // assert(!a.isEmptyStack2());
    // assert(b.isEmptyStack2());
    // cout << "Empty:" << endl;
    // assert(a.isFullStack1());
    // assert(a.isFullStack2());
    // assert(!b.isFullStack1());
    // assert(!b.isFullStack2());
    // cout << "Display" << endl;
    // a.display();
    // b.display();
    
    // TwoStackOptimal<int> a(6);
    // TwoStackOptimal<double> b(6);
    // a.pushFlexStack1(5);
    // a.pushFlexStack1(4);
    // a.pushFlexStack1(3);
    // a.pushFlexStack1(2);
    // cout << "Stack 2: " << endl;
    // a.pushFlexStack2(5);
    // a.pushFlexStack2(4);
    // a.pushFlexStack2(3);
    // a.pushFlexStack2(2);
    // cout << "Pop" << endl;
    // a.popFlexStack1();
    // a.popFlexStack2();
    // cout << "Push 0" << endl;
    // a.pushFlexStack1(0);
    // a.pushFlexStack2(0);
    // // b.popFlexStack1();
    // // b.popFlexStack2();
    // cout << "Full:" << endl;
    // assert(!a.isEmptyStack1());
    // assert(b.isEmptyStack1());
    // assert(!a.isEmptyStack2());
    // assert(b.isEmptyStack2());
    // cout << "Empty:" << endl;
    // assert(a.isFullStack1());
    // assert(a.isFullStack2());
    // assert(!b.isFullStack1());
    // assert(!b.isFullStack2());
    // cout << "Display" << endl;
    // a.display();
    // b.display();
    
    
    stack<int> A, B, C;
    for(int i = 0; i < 3; i++) {
        A.push(i);
        cout << A.top() << ' ';
    }
    cout << endl;
    showTowerStates(3, A, B, C);
    return 0;
}