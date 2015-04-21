//Name: Nicholas Rogers
//SSID: 861152009
//Date: 4/14/15

#include "lab2.h"

//count the number of prime numbers in a numerical singly linked list and implement a helper function
bool isPrime(int i ) {
    for(int index = 2; index <= (i / 2); index++) {
        if (i % index == 0) {
        return false;
        }
    }
    return true;
}
//to judge whether an integer is a prime or not

//recursive function 
//If only i had an iterator to prevent this
int primeCount(forward_list<int> lst) {
    if(lst.empty()) { return 0;}
    forward_list<int> lst2(lst);
    lst2.pop_front();
    if(isPrime(*lst.begin())) { return 1 + primeCount(lst2); }
    return primeCount(lst2);
    
}


// List<T> elementSwap(List<T> lst, int pos) {
//     if(pos > lst.size) { return lst; }
//     Node<T> *traveller = lst.head; 
//     for(int i = 0; i != pos - 1; i++) {
//         traveller= traveller->next;
//     }
//     Node<T> *bridge = traveller;
//     traveller = traveller->next;
//     Node<T>* clone = traveller->next;
//     traveller->next = clone->next;
//     clone->next = traveller;
//     bridge->next = clone;
//     return lst;
// }

//This function is in the header file, but I placed it here to be seen.

// Write a function
template <typename Type>
forward_list<Type> listCopy(forward_list<Type> L, forward_list<Type> P) {
    for(auto x = L.begin(); x != L.end(); x++) {
        P.push_front(*x);
    }
    return P;
}
// to copy a singly linked list L into a second singly linked list P in reverse
// order by only
// traversing L once.

template <typename Type>
void printLots (forward_list<Type> L,forward_list <int> P) {
    int i = 0;
    auto y = P.begin();
    for(auto x = L.begin(); x != L.end(); x++) {
        if(y == P.end()) { 
            cout << endl;
            return; 
        }
        if(i == *y) { 
            cout << *x << ' '; 
            y++;
        }
        i++;
    }
    cout << endl;
}


int main() {
    // ex1
    // forward_list<int> lst;
    // int x = 0;
    // for(cin >> x; x!= -1; cin >> x) {
    //     lst.push_front(x);
    // }
    // cout << primeCount(lst) << endl;
    
    // ex2
    // List<int> a;
    // for(int i = 0; i < 7; i++) {
    //     a.push_front(i);    
    // }
    
    // a.elementSwap(a, 3);
    // a.display();
    
    // ex3
    // forward_list<int> lst,lst2;
    // int x = 0;
    // for(cin >> x; x!= -1; cin >> x) {
    //     lst.push_front(x);
    // }
    // cout << "List 1: ";
    // for(auto x = lst.begin(); x != lst.end(); x++) {
    //     cout << *x << ' ';
    // }
    // cout << endl;
    
    // cout << "List 2: ";
    // lst2 = listCopy(lst, lst2);
    // for(auto x = lst2.begin(); x != lst2.end(); x++) {
    //     cout << *x << ' ';
    // }
    // cout << endl;
    
    // ex4
    forward_list<int> lst,lst2;
    int x = 0;
    cout << "Enter a list of numbers. Enter '-1' to end." << endl;
    for(cin >> x; x!= -1; cin >> x) {
        lst.push_front(x);
    }
    
    cout << "List 1: ";
    for(auto x = lst.begin(); x != lst.end(); x++) {
        cout << *x << ' ';
    }
    cout << endl;
    cout << "Enter a list of numbers in order from largest to smallest. Enter '-1' to end." << endl;
    for(cin >> x; x!= -1; cin >> x) {
        lst2.push_front(x);
    }
    cout << "List 2: ";
    for(auto x = lst2.begin(); x != lst2.end(); x++) {
        cout << *x << ' ';
    }
    cout << endl;
    
    printLots(lst, lst2);
}