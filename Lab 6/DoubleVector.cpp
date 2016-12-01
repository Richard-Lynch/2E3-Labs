//
//  DoubleVector.cpp
//  Vectors
//
//  Created by Richard Lynch on 04/12/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include "DoubleVector.hpp"
#include <iostream>

using namespace std;

// constructor, allocate vector data and initialise size and data
DoubleVector::DoubleVector(int _size)
{
    size = _size;
    data = new double[size];
    for (int i=0; i< size; i++)
        data[i] = 0;
    
    cout << "Constructed." << endl;

}

//copy constructor
DoubleVector::DoubleVector(const DoubleVector &Source)
:size(Source.size)
{
    data = new double[size];
    
    for(int i = 0; i<size; i++)
    {
        data[i] = Source.data[i];
    }
    cout << "Copy Constructed." << endl;

}

// destructor, delete allocated vector data
DoubleVector::~DoubleVector()
{
    
    /*
     for(int i = 0; i < size; i++)
     {
        delete *data[i];
     }
     **/
    delete[] data;
    cout << "Destructed." << endl;
}

//operator
void DoubleVector::operator=(const DoubleVector &Source)
{
    size = Source.size;
    
    delete data;
    
    data = new double[size];
    
    for(int i = 0; i<size; i++)
    {
        data[i] = Source.data[i];
    }
    cout << "Assigned Using Operator." << endl;
}

// returns the size of the vector
int DoubleVector::getSize() const
{
    return size;
}

// print the vector
void DoubleVector::print() const
{
    cout << "[";
    for (int i=0; i< size; i++) {
        cout << data[i];
        if (i<size-1)
            cout <<", ";
    }
    cout << "]" << endl;
}

// returns a reference to the n-th element
double& DoubleVector::operator[](int n)
{
    if(n < size && n >= 0)
    {
        return data[n];
    }
    cout << "Access Error; Position is outside array scope." << endl;
    return throwAway;
    
}

// returns a const reference to the n-th element
const double& DoubleVector::operator[](int n) const
{
    return data[n];
}
