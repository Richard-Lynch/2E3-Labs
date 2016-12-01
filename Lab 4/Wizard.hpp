//
//  Wizard.hpp
//  RPG Game
//
//  Created by Richard Lynch on 03/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#ifndef Wizard_hpp
#define Wizard_hpp
#include "NPC.hpp"

#include <stdio.h>
//the : public NPC here means the Wizard is a TYPE of NPC, its a subclass(which means it automatically has all the same functions)
class Wizard : public NPC
{
public:
    Wizard();//special constructor for a wizard, which overrides the NPC constructor for the wizard
    void defend(int at);//declares a defend funtion especially for a wizard(all the other functions from NPC will apply to wizards , but this one will override print in NPC
    
    void print();//declares a print funtion especially for a wizard(all the other functions from NPC will apply to wizards , but this one will override print in NPC
};



#endif /* Wizard_hpp */
