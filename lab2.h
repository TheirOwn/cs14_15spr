//Name: Nicholas Rogers
//SSID: 861152009
//Date: 4/14/15

#ifndef LAB2_H
#define LAB2_H

#include <forward_list>
#include <iostream>

using namespace std;

template<typename T>
struct Node {
    public:
        Node* next;
        T data;
        Node(T x) : data(x) {} 
};

template<typename T>
class List {
    private:
        Node<T> *head;
        int size;
    public:
        List() :head(0), size(-1) { }
        void push_front(T x) {
            Node<T> *temp = new Node<T>(x);
            temp->next = head;
            head = temp;
            size++;
        }
        List<T> elementSwap(List<T> lst, int pos) {
            if(pos > lst.size) { return lst; }
            Node<T> *traveller = lst.head; 
            for(int i = 0; i != pos - 1; i++) {
                traveller= traveller->next;
            }
            Node<T> *bridge = traveller;
            traveller = traveller->next;
            Node<T>* clone = traveller->next;
            traveller->next = clone->next;
            clone->next = traveller;
            bridge->next = clone;
            return lst;
        }
        void display() {
            for(Node<T> * traveller = head; traveller != 0; traveller = traveller->next) {
                cout << traveller->data << ' ';
            }
            cout << endl;
        }
};

#endif