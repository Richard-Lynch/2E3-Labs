//
//  READ ME
//  EOY_Project
//
//  Created by Richard Lynch on 15/12/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

Main
The main calls several other functions to demonstrate the functionality of the program including;
    1.Setting up instances of the class GPS and Sensor to read from a text file(This is to represent reading directly from real sensors.)
    2.Creates a linked list to store the data provided by the sensors
    3.Calls the addAll function from the linked list(this is designed to be representitive of a thread to read data every second from live sensors and as such delays each read from the text files by 1 second)
    4.The PrintAll function is called which displays the entire linked list, in descending order of z-acceleration(this is to demonstrate that all of the data is being read in and sorted correctly, and that the average has been calculated)
    5.The PrintZ function is called which displays the entries in the linked list, whose z-acceleration is above the threashold(the threshold has been hard coded but code is provided in the printZ funcion to read the threashold from the user), in descending order of z-acceleration(this is to demonstrate that all of the data is being read in and sorted correctly, and that the average has been calculated)

Sensor
This class represents an 3 axis accelerometer, and can be queried for acceleration data which is read from the text file used in its constrcutor
    1.bool getAcceleration(); fetches a new acceleration from the file, stores the data in currX, currY and currZ, and returns true if successful
    2.int getX();int getY();int getZ(); returns the current x y and z value respectivly
    3.Sensor(string sensorData); construcor for the Sensor, takes a string(the name of a text file) as a parameter
    4.~Sensor(); destructor for the Sensor, closes the instream

GPS
This class represents a GPS module, and can be queried for the longitude and latitude which is read from the text file used in its constructor
This is designed in basically the exac same fashion as the Sensor class, but with longitude and latitude instead of acceleration

List
This class is designed to store a linked list of all the data read from the sensors.
    1. a struct called Node is declared, which has x,y,z acceleration and longitude and latidude, aswell as a Node* called next; this is used as a single entry in the linked list
    2.its variabes include;Node* head(top of the list);Node* tail(end of the list);int totalZ(total z acceleration for average);int entries;(number of entries, for average
    3.void add(GPS* gps, Sensor* sensor);adds a node to tail(not used)
    4.void addOrdered(GPS* gps, Sensor* sensor);add a node in descending z order(called by addAll)
    5.void addAll(GPS* gps, Sensor* sensor);takes a gps and sensor object as paramaters and calls addOrdered untill one list is empty(calls print as it adds each empty)
    6.void print(Node* node);//prints a single node(called by addAll and printAll)
    7.void printAll();//prints all the nodes in the list(calls print untill the end of the list is reached)
    8.void printZ();//prints all the nodes above the threshold z(calls print, and filters items in the list below threshold. currently hard coded threshold, code supplied to take user input)
    9.List(); initlises head/tail to null, and totalz/entries to 0
    10.~List(); deletes each entry in the list

Location/Acceleration
Random values over a resonable range were used, but the program can accept any length list

