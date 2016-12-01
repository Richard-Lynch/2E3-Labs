//
//  Stats.cpp
//  RPG Game
//
//  Created by Richard Lynch on 02/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include "Stats.hpp"
#include <iostream>

using namespace::std;


void Stats::setSkill(int sk)
{
    skill = sk;
}

void Stats::setStrength(int st)
{
    strength = st;
}
void Stats::setAlive(bool x)
{
    alive = x;
}

int Stats::getStrength()
{
    return strength;
}

int Stats::getSkill()
{
    return skill;
}

bool Stats::getAlive()
{
    return alive;
}

void Stats::print()
{
    cout << "Strength: " << strength << endl;
    cout << "Skill: " << skill << endl;
    cout << "Alive: ";
    if(alive)
    {cout << "True.";}
    else
    {cout << "False.";}
    
    cout << endl;
}

Stats::Stats (int st, int sk, bool al)
{
    strength = st;
    skill = sk;
    alive = al;
}

