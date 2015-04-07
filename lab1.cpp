#include <iostream>
#include <list>

using namespace std;

template<typename T>
list<T> mergeList(list<T> x, list<T> y) {
    list<T> z;
    if(x.size() == y.size() && x.size() == 0) return z;
    while(true) {
        if(x.size()) {
            z.splice(z.end(), x, x.begin());
        }
        if(y.size()) {
            z.splice(z.end(), y, y.begin());
        }
        if(!y.size() && !x.size()) { return z; }
    }
}

template<typename T>
list<T> mergeSortList(list<T> x, list<T> y) {
    list<T> z;
    if(x.size() == y.size() && x.size() == 0) return z;
    
    typename list<T>::iterator it;
    typename list<T>::iterator thing;
    
    it = x.begin();
    thing = y.begin();
    
    while(true) {
        //cout << *it << ' ' << *thing << endl;
        if(*it <= *thing ) {
            it++;
            z.splice(z.end(), x, x.begin());
        }
        if(*it > *thing) {
            thing++;
            z.splice(z.end(), y, y.begin());
        }
        if(!y.size()) {
            z.splice(z.end(), x);
        }
        if(!x.size()) {
            z.splice(z.end(), y);
        }
        if(!y.size() && !x.size()) { return z; }
    }
}

template<typename T>
void roatateCC(list<T> &x, int n) {
    typename list<T>::iterator it;
    
    for(; n; n--) {
        x.push_back(*x.begin());
        x.pop_front();
    }
    
}

int main() {
    list<int> list1;
    list<int> list2;
    list<int> list3;
    int x = 0;
    
    cout << "First List: ";
    for(int i = 0; i < 5; i++) {
        cin >> x;
        list1.push_back(x);
    }
    
    cout << "Second List: "; 
    for(int i = 0; i < 3; i++) {
        cin >> x;
        list2.push_back(x);
    }
    
    list3 = mergeList(list1, list2);
    
    roatateCC(list1, 6);
     
    list<int>::iterator i;
    for(i=list1.begin(); i != list1.end(); ++i) { cout << *i << " "; }
	   cout << endl;
}