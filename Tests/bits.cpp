//
//  main.cpp
//  bits
//
//  Created by Richard Lynch on 12/05/2016.
//  Copyright © 2016 Lynch. All rights reserved.
//

#include <iostream>

using namespace std;

int checkBit(int x, int y);
int setBit(int x, int y);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int a = 3;
    int b = 3;
    
    cout << checkBit(a, b) << endl;
    
    cout << setBit(a, b) << endl;
    
    return 0;
}

int checkBit(int x, int y)
{
    x &= (1 << y);
    x = (x >> y);
    return x;
}

int setBit(int x, int y)
{
    x |= (1<<y);
    return x;
}