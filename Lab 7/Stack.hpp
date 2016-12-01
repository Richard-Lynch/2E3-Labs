/*
 * Stack
 *
 *  Created on: 16 Nov 2015
 *      Author: dragone
 */

#ifndef Stack_hpp
#define Stack_hpp

class Stack
{
private:
    // At any given time m_SP is also the number of the actual elements stored in the stack
    // Stack pointer, i.e. the index where the next element will be stored
    int m_SP;
    
    int *m_data; // Dynamic array holding the elements
    int m_size;  // The total size of the stack storage
    
public:
    // Push the element onto the top of the stack
    void push(int element);
    
    // Pop the top element off the stack and return in
    int pop();
    
    // Returns the number of actual elements stored on the stack
    int getSize() { return m_SP; };
    
    // Return true if the stack is empty and false otherwise
    bool isEmpty();
    
    // Constructor: size specifies the initial storage capacity of the stack
    Stack(int size);
    
    // deconstructor, frees all allocated space
    ~Stack();
};



#endif /* Stack_hpp */