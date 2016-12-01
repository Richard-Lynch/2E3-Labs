//
//  Student.hpp
//  StudentSort
//
//  Created by Richard Lynch on 19/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

class Student
{
private:
    //Data Atributes(variables)
    string firstName, lastName;
    string studentID, examMark;
    Student* next;
public:
    
    
    //Methods(functions)
    Student();
    string getFirst();
    string getLast();
    string getID();
    string getMark();
    Student* getNext();
    
    void setFirst(string first);
    void setLast(string last);
    void setID(string id);
    void setMark(string mark);
    void setNext(Student* Next);
};

#endif /* Student_hpp */
