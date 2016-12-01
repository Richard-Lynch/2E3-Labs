//
//  Student.cpp
//  StudentSort
//
//  Created by Richard Lynch on 19/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include "Student.hpp"

Student::Student()
{
    next = NULL;
}

string Student::getFirst()
{
    return firstName;
}

string Student::getLast()
{
    return lastName;
}

string Student::getID()
{
    return studentID;
}

string Student::getMark()
{
    return examMark;
}

Student* Student::getNext()
{
    return next;
}

void Student::setFirst(string first)
{
    firstName = first;
}

void Student::setLast(string last)
{
    lastName = last;
}

void Student::setID(string id)
{
    studentID = id;
}

void Student::setMark(string mark)
{
    examMark = mark;
}

void Student::setNext(Student* Next){
    next = Next;
}
