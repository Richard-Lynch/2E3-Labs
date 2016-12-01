//
//  List.cpp
//  EOY_Project
//
//  Created by Richard Lynch on 12/01/2016.
//  Copyright © 2016 Richard. All rights reserved.
//

#include "List.hpp"
#include <thread>         //std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

void List::add(GPS* gps, Sensor* sensor)//not used
{
    Node* newNode = new Node;
    
    //gps->getLocation();
    newNode->Long = gps->getLong();
    newNode->Lat = gps->getLat();
    
    //sensor->getAcceleration();
    newNode->X = sensor->getX();
    newNode->Y = sensor->getY();
    newNode->Z = sensor->getZ();
    
    newNode->next = NULL;
    
    //ADD TO LIST
    if(head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    
    totalZ = totalZ + newNode->Z;
    entries++;
    print(newNode);
}

void List::addOrdered(GPS* gps, Sensor* sensor)
{
    //creates some node pointers
    Node* newNode = new Node;//allocates a node to store our data
    Node* prev  = head;
    Node* curr = head;
    
    //set gps data
    newNode->Long = gps->getLong();
    newNode->Lat = gps->getLat();
    
    //set sensor data
    newNode->X = sensor->getX();
    newNode->Y = sensor->getY();
    newNode->Z = sensor->getZ();
    
    //initialise next to NULL;
    newNode->next = NULL;

    if(head == NULL)//if the list is empty
    {
        head = tail = newNode;
    }
    else
    {
        bool added = false;//lets us leave the while loop when item is added
        while(curr != NULL && added == false)//or leave when at the end of the list
        {
            if(abs(curr->Z) >= abs(newNode->Z))// || -(curr->Z) > newNode->Z)//if the z curr > z new
            {
                prev = curr;
                curr = curr->next;//itterate
            }
            else//if z curr <, add node before
            {
                newNode->next = curr;
                added = true;
                if(curr == head)//if adding before the first item, new head
                {
                    head = newNode;
                }
                else
                {
                    prev->next = newNode;
                }
            }
        }
        
        if(curr == NULL)//if adding to the tail
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    //add z, and entries, then print entry
    totalZ = totalZ + newNode->Z;
    entries++;
    print(newNode);
    
}

void List::addAll(GPS* gps, Sensor* sensor)//reads in the lists until one is empty
{    
    while(gps->getLocation() && sensor->getAcceleration())
    {
        addOrdered(gps, sensor);
        std::this_thread::sleep_for (std::chrono::seconds(1));//sleeps for 1 second
    }

    cout << "Average Z-axis acceleration is: " << (totalZ/entries) << endl;
}

void List::print(Node* node)
{
    cout << "(" << node->Long << ", " << node->Lat << "): " << node->Z << endl;
}

void List::printAll()//goes through the list and calls the print function for each node
{
    cout << endl << "Printing in decending Order of absolute Z-Acceleration:" << endl;
    Node* curr = head;
    while(curr != NULL)
    {
        print(curr);
        curr = curr->next;
    }
    
    cout << "Average Z-axis acceleration is: " << (totalZ/entries) << endl;
}

void List::printZ()
{
    int threshold = 15;
    //this can be used to ask the user for a threshold instead of hardcoding.
    /*
    cout << "Please enter threshold: ";
    cin >> threshold;
    */
    
    Node* curr = head;
    cout << "In decending order of absolute Z-acceleration, above threshold" << endl;
    while(curr != NULL)
    {
        if(abs(curr->Z) > threshold)// || -(curr->Z) > threshold)
        {
            print(curr);
        }
        curr = curr->next;
    }
}

List::List()
{
    //initilise ot null/0
    head = tail = NULL;
    totalZ = entries = 0;
}

List::~List()
{
    //delete all the dynamically allocated memory in the linked list
    Node* curr = head;
    Node* next = curr;
    while(curr->next != NULL)
    {
        next = curr->next;
        delete curr;
        curr = next;
    }
    delete curr;
}
