//
//  main.cpp
//  StudentSort
//
//  Created by Richard Lynch on 19/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include "Student.hpp"
#include "StudentList.hpp"
#include "Stream.hpp"

using namespace::std;

int main(int argc, char *argv[])
{
    //User input
    string choice = "a";
    string fileIn, fileOut;
    Stream prime;
    int c = 10;
    //-------
    
    //dir stuff
    string Directory = argv[0];
    prime.dirChop(Directory);
    string directories[100];
    int size;
    prime.dirIn(Directory, size, directories);
    //-------
    
    //just messing with function pointers here
    int (Stream::*op)(string&, string&, string&, string) = NULL;
    op = &Stream::options;
    //-------
    
    while(!(0 == strcasecmp(&(choice[0]), "Exit")))//while exit has not been selected
    {
        bool choiceOk = false;
        bool fileInOk = false;
        bool fileOutOk = false;
        
        //Offers choices, takes in choice of sort and fileIn fileOut
        //same as c = (prime.*op)(choice, fileIn, fileOut) = prime.options(choice, fileIn, fileOut);
        c = (prime.*op)(choice, fileIn, fileOut, Directory);
        //-------
        
        //check input
        if(0 < c && c <=5)
        {
            choiceOk = true;
        }
        for(int i = 0; i<size; i++)
        {
            if(0==(strcmp(&directories[i][0], &fileIn[0])))
            {
                fileInOk = true;
            }
            if(0==(strcmp(&directories[i][0], &fileOut[0])))
            {
                fileOutOk = true;
            }
        }
        //-------

        //if ok, run, otherwise dont
        if(fileOutOk && fileInOk && choiceOk)
        {
            prime.studentListInOut(c, fileIn, fileOut);
        }
        if(!choiceOk)
        {
            cout << "sortBy: " << choice << ", not found." << endl;
        }
        if(!fileInOk)
        {
            cout << "Input File: " << fileIn << ", not found." << endl;
        }
        if(!fileOutOk)
        {
            cout << "Output File: " << fileOut << ", not found." << endl;
        }
        if(c == 0)
        {
            cout << "Exiting program now." << endl;
            cout << "Number of files in: " << prime.getIn() << endl;
            cout << "Number of files out: " << prime.getOut() << endl;
        }
        //-------
    }
    
    return 0;
}
