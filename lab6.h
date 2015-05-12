#include <iostream>
#include <vector> 
using namespace std;
template<typename L>
void selectionsort(L &l) {
	auto pos_min= l.begin();
	for (auto i = l.begin(); i < l.end(); i++)
	{
	    pos_min = i;//set pos_min to the current index of array
		for (auto j = i + 1; j < l.end(); j++)
		{
		    if (*j < *pos_min) {
                   pos_min = j;
	            //pos_min will keep track of the index that min is in, this is needed when a swap happens
		    }
		}
    		
    	//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
        if (*pos_min != *i)
        {
             swap( *i, *pos_min);
        }
	}
}

void displayPair(vector<pair<int, int> >& z) {
    for(auto x = z.begin(); x < z.end(); x++) {
        cout << "(" << (*x).first << "," << (*x).second << ") ";
    }
    cout << endl;
}

void displayAndSortPair(vector<pair<int, int> >& l) {
    auto pos_min= l.begin();
    int counter = 0;
	for (auto i = l.begin(); i < l.end(); i++)
	{
	    pos_min = i;//set pos_min to the current index of array
		for (auto j = i + 1; j < l.end(); j++)
		{
		    if (*j < *pos_min) {
                   pos_min = j;
	            //pos_min will keep track of the index that min is in, this is needed when a swap happens
		    }
		}
    		
    	//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
        if (*pos_min != *i)
        {
             swap( *i, *pos_min);
             counter = counter + 3;
        }
	}
    
    
    for(auto x = l.begin(); x < l.end(); x++) {
        cout << "(" << (*x).first << "," << (*x).second << ") ";
    }
    cout << endl;
    cout << "0 copies and " << counter << " moves" << endl;
}