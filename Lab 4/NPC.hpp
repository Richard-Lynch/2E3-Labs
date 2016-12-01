//
//  NPC.hpp
//  RPG Game
//
//  Created by Richard Lynch on 02/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#ifndef NPC_hpp
#define NPC_hpp

#include <stdio.h>
#include "Stats.hpp"

class NPC{
    private:
    public:
    Stats NPC_stats;//the NPC has an object(like a variable) called NPC_stats, which is of the type Stats
    
    //the word virtual here allows me to override the print function later on, in wizard other than that you do as normal
    virtual void print();//Print stats(uses the print function from Stats)
    
    Stats getStats();//Get Stats(returns a Stats object)
    void setStats(const Stats& s);//Set Stats(needs to have the adress of a Stats object passed to it, allows you to set an NPCs Stats in one go
    
    int attack();//a method(like a function) which returns the int value for the attack done by the NPC(differnt each time)
    
    //the word virtual here allows me to override the defend function later on, in wizard other than that you do as normal
    virtual void defend(int at);//takes an int value(the attack of an NPC), finds def(diff each time) and calculates damage taken
    
    bool isAlive();//checks if the NPC is alive
    
    //Default Constructor
    NPC();//When making and NPC, no values need to be passed to the constructor, as the NPC will have random stats(you can see this in the implementation file)
   

};

#endif /* NPC_hpp */
