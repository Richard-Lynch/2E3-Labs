//
//  Stream.hpp
//  StudentSort
//
//  Created by Richard Lynch on 20/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#ifndef Stream_hpp
#define Stream_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Student.hpp"
#include "StudentList.hpp"

using namespace::std;

class Stream
{
private:
    int numIn;//number of files input from
    int numOut;//number of files output to
public: 
    int getIn() const;
    int getOut() const;
    
    void studentListIn(ifstream* in, StudentList* list, int choice, string fileIn);//inputs frome fileIn via in, to list, by sort choice
    void studentListout(ofstream* out, StudentList* list, string fileOut);//outputs from list, via out, to fileOut
    void studentListInOut(int choice, string fileIn, string fileOut);//inputs from fileIn via sort choice, and outputs sorted to fileOut
    
    void printOptions(string Directory);//prints the sort, in/out options and the form(called by options)
    int options(string& choice, string& fileIn, string& fileOut, string Directory);//printsOptions, then takes in values
    void dirIn(string name, int& i, string list[]);//reads filenames to list, i records number of items, from dir at name
    void dirOut(int i, string dirs[]);//prints directory list from dirIn
    void dirChop(string& DirCut);//chops the last entry from the path name
    
    Stream();//numIn = numOut = 0
};

#endif /* Stream_hpp */
