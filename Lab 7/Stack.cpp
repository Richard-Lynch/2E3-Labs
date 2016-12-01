/*
 * Stack.cpp
 *
 *  Created on: 16 Nov 2015
 *      Author: dragone
 */

#include "Stack.hpp"
#include <iostream>				// cout
#include <cstdlib>				// exit

// Constructor: size specifies the maximum number of
// elements the user wishes the stack to contain
Stack::Stack(int size)
{
    // Allocate space for the stack's array
    m_data = new int[size];
    m_size = size;
    
    // Set the stack pointer to 0 (stack is empty)
    m_SP = 0;
}

// Destructor, frees all allocated space
Stack::~Stack()
{
    delete[] m_data; // this is how to free an array
}

// Return true if the stack is empty and false otherwise
bool Stack::isEmpty()
{
    return (m_SP == 0);
}

// Push the element onto the top of the stack
void Stack::push(int element)
{
    if (m_SP == m_size) { // has the stack already reached the maximum allowed size?
        std::cout << "Stack overflow, automatic resizing storage capacity to " << (m_size*2) << std::endl;
        int *olddata = m_data;
        m_data = new int [m_size*2];
        for (int i=0; i< m_size; i++) {
            m_data[i] = olddata[i];
        }
        delete[] olddata;
        m_size*=2;
    }
    
    // if we are here it means that m_SP < m_size
    m_data[m_SP++] =  element; // store the element in m_SP position, and
    //update the index where the next element will be stored
}

// Pop the element at the top of the stack
int Stack::pop()
{
    if (m_SP == 0) {
        std::cout << "Stack underflow" << std::endl;
        exit(-1);
    }
    
    // int data = m_data[m_SP-1];
    // m_SP--;
    // return data;
    return m_data[--m_SP]; // does the above in one line
    
}