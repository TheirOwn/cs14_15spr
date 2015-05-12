//Name: Nicholas Rogers
//SSID: 861152009
//Date: 4/27/15
#ifndef TWOSTACKS_H
#define TWOSTACKS_H
#include <iostream>
#include <cassert>
#include <stack>
#include <cstdlib>

using namespace std;

//COMMENT THIS OUT BEFORE SUBMITTING
// #define T int

template < typename T >
class TwoStackFixed {
    private:
        int size;
        int partition;
        T* arr;
        int stack1size;
        int stack2size;
        
        void printStack1() {
            for(int i = 0; i < stack1size; i++) {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
        
        void printStack2() {
            for(int i = 0; i < stack2size; i++) {
                cout << arr[size - i - 1] << ' ';
            }
            cout << endl;
        }
    
    public:
        TwoStackFixed(int size, int maxtop)
        : size(size), partition(maxtop), stack1size(0), stack2size(0) {
            arr = new T [size];            
        }
        
        void pushStack1(T value) {
            if(stack1size + 1 > partition) {
                cout << "Stack limit reached. Could not push stack." << endl;
                return printStack1();
            }
            arr[stack1size++] = value;
            printStack1();
        }
        
        void pushStack2(T value) {
            if(stack2size + 1 > size - partition) {
                cout << "Stack limit reached. Could not push stack." << endl;
                return printStack2();
            }
            arr[size - (++stack2size)] = value;
            printStack2();
        }
        
        T popStack1() { 
            assert(stack1size);
            cout << arr[stack1size--] << endl;
            return arr[stack1size]; 
        }
        
        T popStack2() { 
            assert(stack2size);
            cout << arr[size - 1 - stack2size--] << endl; 
            return arr[size - 1 - stack2size]; 
        }
        
        bool isFullStack1(){
            if(stack1size == partition) { return true; }
            return false;
        }
        bool isFullStack2(){
            if(stack2size == (size - partition)) { return true; }
            return false;
        }
        bool isEmptyStack1(){ return !stack1size; }
        bool isEmptyStack2(){ return !stack2size; }
        void display() {  
            if(!size) { return ; }
            for(int i = 0; i < size; i++) {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
        
};

template < typename T >
class TwoStackOptimal {
    private:
        int size;
        T* arr;
        int stack1size;
        int stack2size;
        
        void printStack1() {
            for(int i = 0; i < stack1size; i++) {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
        
        void printStack2() {
            for(int i = 0; i < stack2size; i++) {
                cout << arr[size - i - 1] << ' ';
            }
            cout << endl;
        }
    
    public:
        TwoStackOptimal(int size)
        : size(size), stack1size(0), stack2size(0) {
            arr = new T [size];            
        }
        
        void pushFlexStack1(T value) {
            if(stack1size + 1 > size - 1 - stack2size) {
                cout << "Stack limit reached. Could not push stack." << endl;
                return printStack1();
            }
            arr[stack1size++] = value;
            printStack1();
        }
        
        void pushFlexStack2(T value) {
            if(size - 1 - stack2size < stack1size) {
                cout << "Stack limit reached. Could not push stack." << endl;
                return printStack2();
            }
            arr[size - (++stack2size)] = value;
            printStack2();
        }
        
        T popFlexStack1() { 
            assert(stack1size);
            cout << arr[stack1size--] << endl;
            return arr[stack1size]; 
        }
        
        T popFlexStack2() { 
            assert(stack2size);
            cout << arr[size - 1 - stack2size--] << endl; 
            return arr[size - 1 - stack2size]; 
        }
        
        bool isFullStack1(){
            if(stack1size == size - stack2size) { return true; }
            return false;
        }
        bool isFullStack2(){
            if(stack1size == size - stack2size) { return true; }
            return false;
        }
        bool isEmptyStack1(){ return !stack1size; }
        bool isEmptyStack2(){ return !stack2size; }
        void display() {  
            if(!size) { return ; }
            for(int i = 0; i < size; i++) {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
        
};
template<typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C, char a, char b, char c) {
if (n==1)
    {
        std::cout << "Moved " << A.top() << " from peg " << a <<" to peg " << c << endl;
        C.push(A.top());
        A.pop();
    }
    else
    {
        showTowerStates(n-1,A,C,B, 'A','C','B');
        std::cout << "Moved " << A.top() << " from peg " << a <<" to peg " << c << endl;
        C.push(A.top());
        A.pop();
        showTowerStates(n-1,B,A,C, 'B','A','C');
    }
}

template<typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C) {
    showTowerStates(n, A, B, C, 'A', 'B', 'C');
}
<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 85454a51aa1fb33c332641ec64fe4c18e559e0ec
