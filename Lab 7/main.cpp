/*
 * main.cpp
 *
 *  Created on: 16 Nov 2015
 *      Author: dragone
 */


#include "Stack.hpp"
#include <iostream>				// cout
#include <cstdlib>				// exit

using namespace std;

#define MAXSIZE 10
#define EXTRA   7

int main()
{
    // Creates a Stack with initial maximum capacity of MAXSIZE
    Stack s(MAXSIZE);
    
    // add more than the capacity, to test that the stack is able to resize itself
    for (int i=0; i<MAXSIZE+EXTRA; i++) {
        s.push(i); // push 0, 1, 2, ... MAXSIZE-1
    }
    
    // at this point we should have a full stack (length == MAXSIZE)
    if (s.getSize() != MAXSIZE+EXTRA) {
        cout << "Test failed: the stack should be full" << endl;
        exit(-1);
    }
    
    // checks that the elements are retrieved in the reverse order, i.e.
    // the first to be retrieved is the last that was added (LIFO, last in, first out)
    for (int i=MAXSIZE+EXTRA-1; i>=0; i--) { // i== MAXSIZE+EXTRA-1, MAXSIZE+EXTRA-2, ... 1, 0
        int data = s.pop();
        cout << "s.pop() == " << data << endl;
        // topElement should be the last to be added, with value = i
        if (data != i) {
            cout << "Test failed: the top element should have been "  << i << endl;
            exit(-1);
        }
    }
    
    
}
