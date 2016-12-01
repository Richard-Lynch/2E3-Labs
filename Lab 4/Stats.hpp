//
//  Stats.hpp
//  RPG Game
//
//  Created by Richard Lynch on 02/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#ifndef Stats_hpp
#define Stats_hpp

#include <stdio.h>

class Stats{
    private:
    int skill;
    int strength;
    bool alive;

    public:
    //Set Stat(sets relevant stat)
    void setSkill(int sk);
    void setStrength(int st);
    void setAlive(bool x);
    //Get Stat(returns relevant stat)
    int getSkill();
    int getStrength();
    bool getAlive();
    //prints NPC
    void print();
    
    //Default Constructor(to make a stats object, you must define strength skill and alive status when declaring)
    Stats (int st, int sk, bool al);
};

#endif /* Stats_hpp */
