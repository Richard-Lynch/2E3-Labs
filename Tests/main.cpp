//
//  main.cpp
//  Test
//
//  Created by Richard Lynch on 20/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace::std;

void test(ifstream* x);

int main(int argc, const char * argv[])
{
    ifstream* stream = new ifstream;
    
    test(stream);
    
    return 0;
}

ifstream* newestS = new ifstream;

void test(ifstream* x)
{
    (*x).open("Student2015SortedTwice.txt");
    
    if((*x).fail())
    {
        cout << "fail." << endl;
    }
    else
    {
        string first, last;
        int id, mark;
        (*x) >> last;
        (*x) >> first;
        (*x) >> id >> mark;
        cout << "First: " << first << endl;
        cout << "Last: " << last << endl;
        cout << "ID: " << id << endl;
        cout << "Mark: " << mark << endl;
        
        
    }
}