//
//  DoubleVector.hpp
//  Vectors
//
//  Created by Richard Lynch on 04/12/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#ifndef DoubleVector_hpp
#define DoubleVector_hpp

#include <stdio.h>

/*
 * Vector of double
 */
class DoubleVector {
    
public:
    // constructor
    DoubleVector(int n);
    
    //copy constructor
    DoubleVector(const DoubleVector &Source);
    
    // destructor
    ~DoubleVector();
    
    //operators
    void operator=(const DoubleVector &Source);
    
    // returns a reference to the n-th element
    double& operator[](int n);
    
    // returns a const reference to the n-th element
    const double& operator[](int n) const;
    
    // returns the size of the vector
    int getSize() const;
    
    // print the vector
    void print() const;
    
private:
    double* data;
    int size;
    
    double throwAway;
    
};

#endif /* DoubleVector_hpp */
