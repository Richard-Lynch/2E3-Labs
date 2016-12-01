//
//  main.cpp
//  DirTest
//
//  Created by Richard Lynch on 21/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
#include <iostream>

using namespace::std;

void dirIn(string name, int& i, string list[]);

int main()
{
    char dirn[500];
    string list[100];
    int i = 0;
    string name;
    DIR *dir = NULL;
    struct dirent *drnt = NULL;
    
    printf("Input directory name: ");
    gets(dirn);
    
    dir=opendir(dirn);
    if(dir)
    {
        
        cout << "Output: " << endl;
        while((drnt = readdir(dir)))
        {
            name = drnt->d_name;
            dirIn(name, i, list);
        }
        closedir(dir);
    }
    else
    {
        cout << "Can not open directory" << dirn << endl;
    }
    
    for(int k = 0; k < i; k++)
    {
        cout << list[k] << endl;
    }
    
    return 0;
}

/*
void dirIn(string name, int& i, string list[])
{
    if(name == "."|| name == ".." || name == ".localized" || name == ".DS_Store")
    {
        
    }
    else
    {
        list[i] = name;
        i++;
    }
}
**/

void dirIn(string name, int& i, string list[])
{
    char dirn[500];
    string dirs[100];
    i = 0;
    DIR *dir = NULL;
    struct dirent *drnt = NULL;
    
    //cout << "Input directory name: ";
    //gets(dirn);
    
    //dirn = "/Users/";
    
    dir=opendir("/Users/");
    if(dir)
    {
        cout << "Output: " << endl;
        while((drnt = readdir(dir)))
        {
            name = drnt->d_name;
            if(name == "."|| name == ".." || name == ".localized" || name == ".DS_Store")
            {
            }
            else
            {
                dirs[i] = name;
                i++;
            }
        }
        closedir(dir);
    }
    else
    {
        cout << "Can not open directory" << dirn << endl;
    }
}

