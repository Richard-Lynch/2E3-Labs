//
//  StudentList.cpp
//  StudentSort
//
//  Created by Richard Lynch on 19/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include "StudentList.hpp"
#include <string.h>
#include <stdlib.h>

int StudentList::cmp(const char *s1, const char *s2, bool isString)
{
    if(isString)//if comparing strings
    {
        if(0<strcasecmp(s1,s2))
            return 1;
        else if(0>strcasecmp(s1,s2))
            return -1;
        else return 0;
                
    }
    else if(!isString)//if comparing ints
    {
        int x = atoi(s1);//convert to ints
        int y = atoi(s2);

        if(x>y)
            return 1;
        else if(x<y)
            return -1;
        else return 0;
    }
    else return NULL;
}

//---------------------------------------------------
void StudentList::addChoice(Student* x, int choice)//adds student with sortBy choice
{
    //---------------------------------------------------
    //Initial setup
    Student* newStudent = x;
    Student* curr = head;
    Student* prev = head;
    
    string (Student::*firstS)();//string function pointers
    string (Student::*secondS)();
    firstS = NULL;
    secondS = NULL;
    //---------------------------------------------------
    //Starting sorted insert
    if(choice > 0 && choice < 5 && head == NULL)//allowed c, and list empty
    {
        head = tail = newStudent;
    }
    else if(choice > 0 && choice < 5)//allowed entry, list not empty
    {
        //---------------------------------------------------
        //1. Setting sort choices
        bool testing, testing2 = 0;//0 = not string, 1 = is string
        if(choice == 1)//last, first
        {
            firstS = &Student::getLast;
            secondS = &Student::getFirst;
            testing = testing2 = 1;
        }
        else if(choice ==2)//first, last
        {
            secondS = &Student::getLast;
            firstS = &Student::getFirst;
            testing = testing2 = 1;
        }
        else if(choice == 3)//ID, last
        {
            firstS = &Student::getID;
            secondS = &Student::getLast;
            testing = 0;
            testing2 = 1;
        }
        else if(choice ==4)//Mark, last
        {
            firstS = &Student::getMark;
            secondS = &Student::getLast;
            testing = 0;
            testing2 = 1;
        }
        else
        {
            cout << "Invalid Choice." << endl;
            return;
        }
        //---------------------------------------------------
        //2. inserting based on sort choice
        while(curr != NULL)//goes through list
        {
            if(0>cmp(&(((newStudent->*firstS)())[0]),&(((curr->*firstS)())[0]), testing))//if new value is smaller than the curr
            {
                insert(curr, prev, newStudent);//insert at curr pos
                return;
            }
            else if(0<cmp(&(((newStudent->*firstS)())[0]),&(((curr->*firstS)())[0]), testing))//if new value is bigger than the curr
            {
                prev = curr;//iterate
                curr = curr->getNext();
            }
            else
            {
                if(0>cmp(&(((newStudent->*secondS)())[0]),&(((curr->*secondS)())[0]), testing2))
                {
                    insert(curr, prev, newStudent);
                    return;
                }
                else
                {
                    prev = curr;
                    curr = curr->getNext();
                }
            }
        }//end of 2.
        insert(curr, prev, newStudent);//if its higher alphabetically then everyhting else on the list we still need to insert
    }//end of else if
}

            
void StudentList::insert(Student* curr, Student* prev, Student* newStudent)//inserts at curr location
{
    if(curr == head)//if head
    {
        newStudent->setNext(head);//point to head
        head = newStudent;//change head
        return;
    }
    else if(curr == NULL)//if tail
    {
        newStudent ->setNext(NULL);//point to null
        prev->setNext(newStudent);//point prev(tail) to new
        tail = newStudent;//tail = new
        return;
    }
    else//if middle
    {
        newStudent ->setNext(prev->getNext());//point new to prev->next
        prev->setNext(newStudent);//point prev to new
        return;
    }
}

StudentList::StudentList()//initilaise head/tail
{
    head = tail = NULL;
    cout << "List constructed. " << endl;
}

StudentList::~StudentList()//empty list
{
    Student* curr = head;
    Student* next = head->getNext();
    while(next != NULL)
    {
        delete curr;
        curr = next;
        next = curr->getNext();
    }
    delete curr;
    cout << "List destructed." << endl;
}

Student* StudentList::getHead() const
{
    return head;
}
Student* StudentList::getTail() const
{
    return tail;
}
void StudentList::setHead(Student* h)
{
    head = h;
}
void StudentList::setTail(Student* t)
{
    tail = t;
}
