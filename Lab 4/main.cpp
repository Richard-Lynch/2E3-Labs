//
//  main.cpp
//  RPG Game
//
//  Created by Richard Lynch on 02/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include <iostream>
#include "NPC.hpp"
#include "Team.hpp"
#include "Stats.hpp"
#include <time.h>
#include <stdlib.h>
#include "Wizard.hpp"


using namespace::std;

int main() {
    
    srand (time(0));
    
    cout << "Please enter the number of NPCs per team." << endl;
    int num;
    cin >> num;
    cout << "Please enter the number of rounds." << endl;
    int round;
    cin >> round;
    
    //creates teams
    Team one;
    Team two;
    
    //declares variables for the positon of the wizard within the team
    int wizard1;
    int wizard2;
    
    
    if(num == 1)//if the team only has 1 NPC, we always want wizard to be the fist(only) NPC
    {
        wizard1 = 0;
        wizard2 = 0;
    }
    else if(num > 1)//if the team has more than one NPC, we want the wizard to be in some random position, from 0 to the number of NPCs in the team
    {
        wizard1 = rand()%(num);
        wizard2 = rand()%(num);
    }
    else//if there are 0 or less than 0 NPCs, set to 0(just cus)
    {
        wizard1=wizard2=0;
    }
    
    
    //output the wizard position, just so ya know where they should be
    cout << " wizard 1: " << wizard1 << endl;
    cout << " wizard 2: " << wizard2 << endl;

    
    if(num > 0)//if there is at least 1 NPC in the team
    {
        //for each value from 0 to the number of NPCs the user wants, this block create an NPC and add to correct team
        for(int i=0; i<num; i++)
        {
            //__________________
            //this block adds an NPC to Team 1
            
            if(i == wizard1)//if we're currently adding an NPC to the position in Team 1 we want to put a Wizard, make a wizard
            {
                NPC* New1 = new Wizard;//allocate memory for a new wizard, and set an NPC pointer(Important) to point to them
                one.add(New1);//use that pointer to add them to the team
            }
            else // if we're not at a wizard positon add an NPC
            {
                NPC* New1 = new NPC;//allocate memory for a new NPC, and use an NPC pointer to point to them
                one.add(New1); //use that pointer to add them to the team
            }
            //___________________
            
            //This does the same for Team 2
            if(i == wizard2)
            {
                NPC* New2 = new Wizard;
                two.add(New2);
            }
            else
            {
                NPC* New2 = new NPC;
                two.add(New2);
            }
        }
        
        cout << endl;
        
        for(int j = 1; j <= round; j++)//just loops for the current round (you dont have to include rounds I dont think)
        {
            cout << "Round: " << j << endl;
            //***************
            //This block is
            //Team 1 attacking
            for(int i=0; i<num; i++)
            {
                cout << "Match " << (i+1) << endl;
                if(one.at(i)->isAlive())//check player attacking is alive
                {
                    if(two.at(i)->isAlive())//check player being attacked is alive
                    {
                        two.at(i)->defend(one.at(i)->attack());//perform attack
                        cout << "position" << endl;//shouldnt be here, dunno why I did that
                        two.at(i)->print();//print player that was attacked
                        
                        cout << endl;
                    }
                    else//if the player being attacked is dead
                    {
                        cout << "Player " << i+1 << " on team two is dead, so cannot attack." << endl<< endl;
                    }
                }
                else if(two.at(i)->isAlive())//if the player attacking is dead, but the player being attacked isnt
                {
                    cout << "Player " << i+1 << " on team one is dead, so cannot attack." << endl<< endl;
                }
                else//if both players are dead
                {
                    cout << "Both players are dead, so no fight" << endl<< endl;
                }
            }
            //************
            
            //Same as for Team 1
            //Team two attacking
            for(int i=0; i<num; i++)
            {
                cout << "Match " << (num+i+1) << endl;
                if(two.at(i)->isAlive())
                {
                    if(one.at(i)->isAlive())
                    {
                        one.at(i)->defend(two.at(i)->attack());
                        one.at(i)->print();
                        cout << endl;
                    }
                    else
                    {
                        cout << "Player " << i+1 << " on team one is dead, so cannot attack." << endl<< endl;
                    }
                }
                else if(one.at(i)->isAlive())
                {
                    cout << "Player " << i+1 << " on team two is dead, so cannot attack." << endl<< endl;
                }
                else
                {
                    cout << "Both players are dead, so no fight" << endl<< endl;
                }
            }
            
        }

    }
    
    //Checks who won
    if(num == 0)//if there were no NPCs in the teams, so no fights
    {
        cout << "There were no players on either team!" << endl;
    }
    else if(one.numAlive() > two.numAlive())//if number alive Team 1 is great than Team 2, Team 1 wins
    {
        cout << "Team one wins!" << endl;
    }
    else if(two.numAlive() > one.numAlive())//if number alive Team 2 is great than Team 1, Team 2 wins
    {
        cout << "Team Two wins!" << endl;
    }
    else//if the same, draw
    {
        cout << "Its a draw!" << endl;
    }
    
    return 0;
}
