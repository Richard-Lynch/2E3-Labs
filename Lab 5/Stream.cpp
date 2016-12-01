//
//  Stream.cpp
//  StudentSort
//
//  Created by Richard Lynch on 20/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include "Stream.hpp"
#include <iomanip>
#include <string.h>

//for Dir
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
#include <iostream>

using namespace::std;

Stream::Stream()
{
    numIn = numOut = 0;
}

void Stream::studentListInOut(int choice, string fileIn, string fileOut)//input and sort by choice from fileIn, output to fileOut
{
    ifstream *In = new ifstream;//declare file in stram
    StudentList *List = new StudentList;//allocate new StudentList
    studentListIn(In, List, choice, fileIn);//call studentListIn(input and sort by choice from fileIn to list)
    //studentListIn(new ifstream, new StudentList, choice, fileIn);//wanted to try delcaring as I passed but couldnt think fo how to delete.
    delete In;//delete in stream
    
    ofstream *Out = new ofstream;//declare file out stream
    studentListout(Out, List, fileOut);//call studentListOut(print from list to fileOut)
    delete List;//delete StudentList to free memory
    delete Out;//delete out stream
}

void Stream::studentListIn(ifstream* in, StudentList* list, int choice, string file)
{
    in->open(file);//open file with in tream
    
    if(in->fail())//if fail outout error
    {
        cout << "Could not open input file." << endl;
    }
    else
    {
        cout << "Opened Successfully." << endl;
        while(!in->eof())//while not at the end of file
        {
            //cout << "Starting read number: " << i << endl;
            Student* student = new Student;//new student
            string first, last, id, mark;
            *in >> last >> first >> id >> mark;
            student->setLast(last);
            student->setFirst(first);
            student->setID(id);
            student->setMark(mark);
            list -> addChoice(student, choice);//add to list
        }
        cout << "Read Successfully." << endl;
        
        numIn++;//increase number of files read in
    }
    in->close();//close file
}


void Stream::studentListout(ofstream* out, StudentList* list, string file)
{
    out->open(file);//open file
    if(out->fail())//if fail error message
    {
        cout << "Could not open output file" << endl;
    }
    else
    {
        Student* curr = list->getHead();//start at the top of the list
        while(curr != NULL)//while not at the end, print list to file, with correct widths etc
        {
            *out <<  setw(12) << setfill (' ') << left <<  curr->getLast() << setw(12) << setfill (' ') << left << curr->getFirst() << " " << setw(12) << setfill (' ') << left << curr->getID() << setw(4) << setfill (' ') << left << curr->getMark();
            if(curr->getNext() != NULL)//when at the last item, dont enter a new line
            {
                *out << endl;
            }
            curr = curr->getNext();//iterate
        }
        cout << "Saved Successfully." << endl;
        numOut++;//inscrease number of files saved to
    }
    out->close();//close file
}

void Stream::printOptions(string Directory)
{
    int size;//number of files in dir
    string directories[100];//list of filenames
    cout << endl;
    cout << "sortBy:    Last, First, ID, Mark" << endl;
    cout << "In/Out:    ";
    dirIn(Directory, size, directories);//take in the list of filenames at dir
    dirOut(size, directories);//output this list(these are the possible file in/outs)
    cout << "Form:      sortBy In.txt Out.txt" << endl;
    cout << "To Exit:   Exit" << endl;
}

int Stream::options(string& choice, string& fileIn, string& fileOut, string Directory)
{
    Stream::printOptions(Directory);//call print options to display possible inputs
    
    cin >> choice;//take in choice first so user can just enter exit
    
    if(0 == strcasecmp(&(choice[0]), "Exit"))//if exit, return
    {
        return 0;
    }
    
    cin >> fileIn >> fileOut;//otherwise cin filenames
    //compare sort options to allowed options, if allowed return choice number, if not allowed, return -1;
    if(0 == strcasecmp(&(choice[0]), "Last"))
    {
        return 1;
    }
    else if(0 == strcasecmp(&(choice[0]), "First"))
    {
        return 2;
    }
    else if(0 == strcasecmp(&(choice[0]), "ID"))
    {
        return 3;
    }
    else if(0 == strcasecmp(&(choice[0]), "Mark"))
    {
        return 4;
    }
    else
    {
        return -1;
    }
}

void Stream::dirIn(string name, int& i, string dirs[])
{
    i = 0;
    DIR *dir = NULL;//directory pointer
    struct dirent *drnt = NULL;//a directory entry structure, holds info about a particular file in the dir
    
    
    //convert string to char[]
    string Direc=name;
    long TempNumOne=Direc.size();
    char dirn[TempNumOne];
    for (long a=0;a<=TempNumOne;a++)
    {
        dirn[a]=Direc[a];
    }
    //-----------------------
    
    dir=opendir(dirn);//open dirn, the name enerted
    if(dir)//if it didnt fail
    {
        while((drnt = readdir(dir)))//reads a new file and sets drnt to = it(this automatically iterates to next item in dir)
        {
            name = drnt->d_name;//take in name of file
            if(name == "."|| name == ".." || name == ".localized" || name == ".DS_Store"|| name == "StudentSort")//ignore if these names
            {
            }
            else//else add to list
            {
                dirs[i] = name;
                i++;
            }
        }
        closedir(dir);//close directory
    }
    else//if fail
    {
        cout << "Can not open directory" << dirn << endl;
    }
}

void Stream::dirOut(int i, string dirs[])//output directory as list on one line
{
    for(int k=0; k<(i-1); k++)
    {
        cout << dirs[k] << ", ";
    }
    cout << dirs[(i-1)] << ". " << endl;
}

void Stream::dirChop(string& DirCut)//chops the last entry from the given path
{
    //cout << "Full Direct: " << DirCut << endl;//output starting path
    long k = DirCut.size()-1;//where to start chopping(end of path)
    long chop = 0;//number of chars chopped
    while(DirCut[k] != '/')//chop untill /
    {
        k--;//decrease the position in the char[] each time
        chop++;//increase the number chopped each time
    }
    
    long DirectSize = (DirCut.size()) - chop;//the new length of the array
    //cout << "DirectSize: " << DirectSize << endl;
    
    for(long i = DirectSize; i < (DirectSize+11); i++)
    {
        DirCut[i] = NULL;//empty the unwanted items in the array
    }
    
   //cout << "Choped Direct:" << DirCut << endl;//print new path
}


int Stream::getIn() const
{
    return numIn;
}

int Stream::getOut() const
{
    return numOut;
}
