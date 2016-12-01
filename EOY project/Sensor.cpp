//
//  Sensor.cpp
//  EOY_Project
//
//  Created by Richard Lynch on 15/12/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include "Sensor.hpp"





bool Sensor::getAcceleration()
{
    if(!In->eof())//while not at the end of file
    {
        *In >> currX;
        *In >> currY;
        *In >> currZ;
        //cout << "Sensor read Succesful." << endl;
        return true;
        /*
         list -> addChoice(student, choice);//add to list
         **/
    }
    else return false;
}

Sensor::Sensor(string sensorData)
{
    In = new ifstream;
    In->open(sensorData);
    
    if(In->fail())//if fail outout error
    {
        cout << "Could not open Sensor file." << endl;
    }
    else
    {
        cout << "Sensor opened successfully." << endl;
    }
}

Sensor::~Sensor()
{
    In->close();
}

int Sensor::getX()
{
    return currX;
}

int Sensor::getY()
{
    return currY;
}

int Sensor::getZ()
{
    return currZ;
}