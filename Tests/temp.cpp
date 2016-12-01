//
//  temp.cpp
//  DirTest
//
//  Created by Richard Lynch on 21/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include "temp.hpp"

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

void dirIn(string name, int i, string list[]);

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
    
    for(int k = 0; k <= i; k++)
    {
        cout << list[i] << endl;
    }
    
    return 0;
}

void dirIn(string name, int i, string list[])
{
    if(name == "."|| name == ".." || name == ".localized")
    {
        
    }
    else
    {
        list[i] = name;
        i++;
    }
}

