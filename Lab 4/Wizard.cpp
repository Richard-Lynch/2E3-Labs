//
//  Wizard.cpp
//  RPG Game
//
//  Created by Richard Lynch on 03/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include "Wizard.hpp"
#include "Stats.hpp"
#include "NPC.hpp"
#include <iostream>
using namespace::std;

Wizard::Wizard()//constructs a wizard
:NPC()//uses the NPC constructor as normal
{cout << "wizard construced" << endl;}//the adds to it by outputting "wizard constructed"

void Wizard::defend(int at)//new defend function just for wizard, overrides NPC defend
{
    NPC::defend(at);//calls NPC defend as normal
    if(getStats().getStrength() <= 0)//if they were killed, as in strength is <=0, runs this little command that sets the stregth back to 1 and alive to true
    {
        cout << "The Boy Who Lived!" << endl;//outputs this so we know they've been revived
        setStats(Stats (1, (getStats().getSkill()), true));//sets stats to (st=1, sk=sk, alive=true)
    }
}

void Wizard::print()//overrides the normal NPC print
{
    cout << "You're a Wizard Harry!" << endl;//outputs this so we know its  a wizard being printed
    NPC_stats.print();//then uses the normal print funtion
}


