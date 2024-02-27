#include <iostream>
#include <string>
#include <cstdlib>
#include "heap.h"

using namespace std;

int main(){
    
    
    srand(3764);
    for (int i = 0; i < 50; i++){
        Heap<int> myHeap = Heap<int, std::less<int>>(12);
        for (int i = 0; i < 50; i++){
            int rn = 1 + (rand() % 200);
            myHeap.push(rn);
        }
        cout << "Trial " << i+1 << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        for (int j = 0; j < 50; j++){
            if (j == 26) {cout << endl;}
            cout << myHeap.top() << " ";
            myHeap.pop();
        }
        cout << endl; 
        cout << "-------------------------------------------------------------------------" << endl;
        cout << endl; 
    }

    return 0;
}
