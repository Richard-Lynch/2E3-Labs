//
//  main.cpp
//  EOY_Project
//
//  Created by Richard Lynch on 15/12/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include <iostream>
#include "Sensor.hpp"
#include "GPS.hpp"
#include "List.hpp"

int main(int argc, const char * argv[])
{
    GPS GPS_1("Location.txt");
    Sensor Sensor_1("Acceleration.txt");
    List Journey;
    cout << endl;
    
    cout << "Adding All:" << endl;
    Journey.addAll(&GPS_1, &Sensor_1);
    cout << "Finished Adding All." << endl;
    
    Journey.printAll();
    cout << "Finished Printing All." << endl << endl;
    
    Journey.printZ();
    cout << "Finished Printing Above Threshold." << endl;
    
    cout << endl;
    
    return 0;
}


