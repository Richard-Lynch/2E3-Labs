//
//  Team.hpp
//  RPG Game
//
//  Created by Richard Lynch on 02/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#ifndef Team_hpp
#define Team_hpp

#include <stdio.h>
#include "NPC.hpp"


class Team{
private:

    
    
public:
    void add(NPC* npc);//method(function) which adds a NPC to the end of a team, useing an NPC pointer
    int size();//returns size of team
    NPC* at(int i);//returns the pointer(address of) the NPC at positon i in the team
    int numAlive();//counts the number of NPCs alive in the team
    struct Node//linked list structure
    {
        
        NPC* x;//contains a NPC pointer
        Node* next;//pointer to the next node.
        
        
    };
    Node* head = NULL;//has a head
    Node* tail = NULL;//and a tail
    //NOTE: these will be differnt for each team, so we can declare Team 1 and then Team 2, they will have difernt heads etc, and will not overlap
    
};

#endif /* Team_hpp */
