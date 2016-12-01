//
//  GPS.hpp
//  EOY_Project
//
//  Created by Richard Lynch on 15/12/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#ifndef GPS_hpp
#define GPS_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

class GPS
{
public:
    double currLong;
    double currLat;
    ifstream* In;
    
    bool getLocation();//fetches a new location from the file, stores the data in currLong and currLAt and returns true if successful
    double getLong();//retuns currLong
    double getLat();//returns currLat
    
    GPS(string GPS_DATA);
};

#endif /* GPS_hpp */
