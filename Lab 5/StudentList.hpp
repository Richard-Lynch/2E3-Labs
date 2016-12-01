//
//  StudentList.hpp
//  StudentSort
//
//  Created by Richard Lynch on 19/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#ifndef StudentList_hpp
#define StudentList_hpp

#include <stdio.h>
#include "Student.hpp"

class StudentList
{
private:
    //Data Memebers(Variables)
    Student* head;//top of list
    Student* tail;//bottom of list
    
public:
    //Methods(Functions)
    void addChoice(Student* x, int choice);//adds student with coresponding sort choice
    void insert(Student* curr, Student* prev, Student* newStudent);//called by addChoice, inserts at current list position
    int cmp(const char *s1, const char *s2, bool isString);//compares two strings, ignoreing case, and if isString = false, convert to int
    Student* getHead() const;
    Student* getTail() const;
    void setHead(Student* h);
    void setTail(Student* t);
    
    StudentList();//head = tail = NULL
    ~StudentList();//deletes all dyn mem, empties list
};

#endif /* StudentList_hpp */
