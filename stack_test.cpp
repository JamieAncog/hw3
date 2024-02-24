#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    Stack<string> Alph;
    Alph.push("A");
    Alph.push("B");
    Alph.push("C");
    Alph.push("D");
    cout << "Empty: " << Alph.empty() << endl;
    cout << "Size: " << Alph.size() << endl;
    int size = Alph.size();
    for (int i = 0; i < size; i++){
        cout << "Top: " << Alph.top() << endl;
        Alph.pop();
    }
    return 0;
}