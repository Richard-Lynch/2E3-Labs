//
//  Sensor.hpp
//  EOY_Project
//
//  Created by Richard Lynch on 15/12/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#ifndef Sensor_hpp
#define Sensor_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

class Sensor
{
public:
    int currX;
    int currY;
    int currZ;
    ifstream* In;
    
    bool getAcceleration();//fetches a new acceleration from the file, stores the data in currX, currY and currZ, and returns true if successful
    int getX();
    int getY();
    int getZ();
    
    Sensor(string sensorData);
    ~Sensor();
};

#endif /* Sensor_hpp */
