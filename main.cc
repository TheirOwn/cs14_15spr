#include "lab6.h"

template <typename T>
struct dataHolder
{
    static int changeId;
    
    dataHolder(T val) : data(val) , id(changeId) {++changeId;}
    
    T data;
    int id;
    
    bool operator< (dataHolder& x) {
        return ((*this).data < x.data);
    }
    
    bool operator!= (dataHolder& x) {
        return ((*this).data != x.data);
    }
};

template <typename T>
int dataHolder<T>::changeId = 0;

int main() {
    cout << "pre: ";
    vector<int> a = {2, 4, 5, 1, 9, 8};
    for(unsigned i = 0; i < a.size(); i++) {
        cout << a.at(i) << ' ';
    }
    cout << "\npost: ";
    selectionsort(a);
    for(unsigned i = 0; i < a.size(); i++) {
        cout << a.at(i) << ' ';
    }
    cout << endl;
    
    cout << "pre: " << endl;
    vector<double> b;
    selectionsort(b);
    cout << "post: ";
    for(unsigned i = 0; i < b.size(); i++) {
        cout << b.at(i) << ' ';
    }
    cout << endl;
    cout << "pre: ";
    vector<pair<int,int> > c = {pair<int,int> (1,2), pair<int,int> (3,-1), 
        pair<int,int> (-1,3), pair<int,int> (0,0), pair<int,int> (2,3), 
        pair<int,int> (1,2), pair<int,int> (1,-2), pair<int,int> (8,10) };
    displayPair(c);
    cout << "post: ";
    displayAndSortPair(c);
    cout << "pre: ";
    vector<pair<int,int> > d = { pair<int,int> (10,2), pair<int,int> (-3,-1), 
        pair<int,int> (-8,0), pair<int,int> (1,1), pair<int,int> (1,1), 
        pair<int,int> (0,0), pair<int,int> (10,2), pair<int,int> (5,5), 
        pair<int,int> (5,-5), pair<int,int> (0,0), pair<int,int> (10,2)};
    displayPair(d);
    cout << "post: "; 
    displayAndSortPair(d);
    cout << "pre: ";
    vector<pair<int,int> > e = { pair<int,int> (-1,3), pair<int,int> (0,0), 
        pair<int,int> (1,-2), pair<int,int> (1,2), pair<int,int> (1,2), 
        pair<int,int> (2,3), pair<int,int> (3,-1), pair<int,int> (8,10)};
    displayPair(e);
    cout << "post: ";
    displayAndSortPair(e);
    
    
// A: No it is not. For the following example: (if it was sorting to be reverse alphabetical)
// A A B C D
// D A B C A
// D C B A A
// The First A is moved to the back, and the second A is moved to the 
// second to last position when it swaps with C. So they are now in a different 
// order than when it started
//
//B)
    cout << "Proof that it is not stable: " << endl;
    vector<dataHolder<int> > f = { dataHolder<int>(5), dataHolder<int>(5), 
        dataHolder<int>(1)};
    for(unsigned i = 0; i < f.size(); i++) {
        cout << (f.at(i)).data << " id is " << (f.at(i)).id << ", ";
    }
    cout << endl;
    selectionsort(f);
    for(unsigned i = 0; i < f.size(); i++) {
        cout << (f.at(i)).data << " id is " << (f.at(i)).id << ", ";
    }
    cout << endl;
    //
}


