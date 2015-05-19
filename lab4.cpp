//Name: Nicholas Rogers
//SSID: 861152009
//Date: 4/27/15
#include "lab4.h"


int main(int argc, char *argv[]) {
    if(argc < 2) { 
        cout << "Error. Command is ./<name> <int>." << endl;
        return 0; 
    }
    cout << "pre-order\n";
    preOrder(atoi(argv[1]));
    cout << "post-order\n";
    postOrder(atoi(argv[1]));
    cout << "sorted\n";
    sorted(atoi(argv[1]));
}
