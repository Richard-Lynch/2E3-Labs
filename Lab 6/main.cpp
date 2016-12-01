//
//  main.cpp
//  Vectors
//
//  Created by Richard Lynch on 04/12/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include "DoubleVector.hpp"
#include <iostream>
#include <stdio.h>


using namespace::std;

int main() {
    DoubleVector x(4);
    x[0] = 0;
    x[1] = 5;
    cout << "x.print(): ";
    x.print();
    
    //Your task is to uncomment the following 3 lines and make the following work
    DoubleVector y = x;
    y[2] = 3;
    cout << "y.print(): ";
    y.print(); // this should print [0, 5, 3, 0]
    
    //Copy Constructor
    DoubleVector z(x);
    cout << "z.print(): ";
    z.print();
    
    cout << "x[1] = 1: ";
    x[1] = 1;
    
    cout << "x.print(): ";
    x.print();
    cout << "z.print(): ";
    z.print();
    
    DoubleVector q(2);
    q[0] = 1;
    cout << "q.print(): ";
    q.print();
    q[1] = 2;
    cout << "q.print(): ";
    q.print();
    q[2] = 3;
    cout << "q.print(): ";
    q.print();
    q[3] = 4;
    cout << "q.print(): ";
    q.print();
    
    cout << q[2] << endl;
    cout << q[3] << endl;
    
    return 0;
}