//
//  GPS.cpp
//  EOY_Project
//
//  Created by Richard Lynch on 15/12/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include "GPS.hpp"

using namespace std;


bool GPS::getLocation()
{
    if(!In->eof())//while not at the end of file
    {
        *In >> currLong;
        *In >> currLat;
        //cout << "GPS read Succesful." << endl;
        return true;
     /*
        list -> addChoice(student, choice);//add to list
        **/
    }
    else return false;
}

GPS::GPS(string GPS_DATA)
{
    In = new ifstream;
    In->open(GPS_DATA);
    
    if(In->fail())//if fail outout error
    {
        cout << "Could not open GPS file." << endl;
    }
    else
    {
        cout << "GPS opened successfully." << endl;
    }
}

double GPS::getLong()
{
    return currLong;
}

double GPS::getLat()
{
    return currLat;
}