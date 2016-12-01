//
//  List.hpp
//  EOY_Project
//
//  Created by Richard Lynch on 12/01/2016.
//  Copyright © 2016 Richard. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

#include "Sensor.hpp"
#include "GPS.hpp"

struct Node
{
    int X, Y, Z;
    double Long, Lat;
    
    Node* next;
};

class List
{
public:
    Node* head;
    Node* tail;
    int totalZ;
    int entries;
    
    
    void add(GPS* gps, Sensor* sensor);//adds a node to tail(not used)
    void addOrdered(GPS* gps, Sensor* sensor);//add a node in descending z order
    void addAll(GPS* gps, Sensor* sensor);//calls addOrdered untill one list is empty
    void print(Node* node);//prints a node
    void printAll();//prints all the nodes in the list
    void printZ();//prints all the nodes above the threshold
    List();
    ~List();
    
};

#endif /* List_hpp */
