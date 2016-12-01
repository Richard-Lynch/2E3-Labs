//
//  NPC.cpp
//  RPG Game
//
//  Created by Richard Lynch on 02/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include "NPC.hpp"
#include "Stats.hpp"
#include "Wizard.hpp"
#include <iostream>
using namespace::std;

void NPC::print(){
    NPC_stats.print();//calls the Stats print function for NPC_stats
}

NPC::NPC()
: NPC_stats(((rand()%20)+1), ((rand()%5)+1), true)//sets the NPC_stats to:(st=(rand from 1-20), sk=(rand from 1-6), alive=true)
{
    cout << "NPC constructed." << endl;//outputs this when theyre created for the first time
}

int NPC::attack()//takes no variable
{
    int skill = getStats().getSkill();//retrieves the Skill from NPC_stats
    //cout << "Skill Attack: " << skill <<endl; (doesnt need to be here)
    return (skill*((rand()%5)+1));//returns (skill*(rand from 1-6)) as in skill multiplied by a dice roll((this is the attack done

}



void NPC::defend(int at)//takes an int, normally the attack of the other NPC
{
    int skill = getStats().getSkill();//retrieves Skill from NPC_stats
    int def =  (skill*((rand()%5)+1));//calculates def same as Attack(skill*dice roll)
    //cout << "Skill def: " << skill << endl; (dont use this)
    cout << "Skill: " << skill << ". Defence: " << def  << "." << endl;
    int damage = at - def;//calculates damage as attack-defence
    cout << "Attack: " << at << endl;
    cout << "Damage: " << damage << endl;
    if(damage > 0)//if damage > 0, as in attack > def
    {
        int health = getStats().getStrength();//retrieve strength from NPC_stats
        int n_health = health - damage;//set new health to health - damage done
        setStats(Stats (n_health, (getStats().getSkill()), true));//set NPC_stats to;(strength=(new health), skill = skill, alive=true)
        
        if(getStats().getStrength() <= 0)//if new strength is less than or equal to 0 (as in the NPC is dead)
        {
            setStats(Stats (0, (getStats().getSkill()), false));//sets alive to dead,sets NPC_Stats to;(strength=strength, skill = skill, alive=false)
        }
    }
}


bool NPC::isAlive()//returns true if alive
{
    if(getStats().getAlive() == true)//retreive alive from NPC_stats and if true, return true
    {
       return true;
    }
    else
    return false;
}

Stats NPC::getStats()
{
    return NPC_stats;//just returns the Stats object held by NPC, NPC_stats
}

void NPC::setStats(const Stats& s)
{
    NPC_stats = s;//Sets NPC_stats to equal the Stats passed to the variable.
}