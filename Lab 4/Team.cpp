//
//  Team.cpp
//  RPG Game
//
//  Created by Richard Lynch on 02/11/2015.
//  Copyright © 2015 Richard. All rights reserved.
//

#include "Team.hpp"

void Team::add(NPC* npc)//takes an NPC pointer and adds that NPc to the back of the list
{
    Node* newNode = new Node;//allocates memory for a new node, and points newNode to it
    newNode->x = npc;//sets the x value in that node, to the adress of the NPC being added
    newNode->next = NULL;//sets the next value of the node to NULL, cus it is the end of the list
    if(tail != NULL)//if the tail isnt null, as in there is at least one item in the list
    {
        tail->next = newNode;//point the item currently pointed to by tail, at the new node(we've added it to the end of the list)
    }
    if(head == NULL)//if there are no NPC in the list
    {
        head = newNode;//we want new node to be pointed to by head(it is the first item in the list
    }
    tail = newNode;//we always want tail to point to the newest node
    
}


int Team::size()//returns the number of NPCs stored in the list
{
    Node* curr = head;//created a temp pointer called curr, which starts at the head
    int i = 0;//set i to 0(this will be the number of NPCs in the list)
    if(head == NULL)//if head = null, the list is empty
        return 0;
    else if(head == tail)//if head = tail, there is one item in the list
        return 1;
    else//otherwise, iterate till you get to tail then cout i, which will be the number in the list
    {
        i = 1;
        while(curr->next != NULL)//while we're not at the last item
        {
            i++;
                curr = curr ->next;//set curr to the next node in the list
    }
        return i;//out i, the number of NPCs in the list
    }
    
}

int Team::numAlive()//returns the number of NPCs alive in the team
{
    Node* curr = head;//created a temp pointer called curr, which starts at the head
    int i = 0;//set i to 0(this will be the number of LIVING NPCs in the list)
    if(head == NULL)//if head = null, the list is empty
    {
      return 0;
    }
    else//otherwise start counting number alive
    {
        i = 0;
        while(curr->next != NULL)//while we're not at the last node
        {
            if(curr->x->isAlive())//if current NPC is alive(as in there is an NPC pointed to by x, and if the NPC method "isAlive" returns true)
            {
                i++;//add one to the number alive
            }
            curr = curr ->next;//goes to the next node
        }
        if(curr->x->isAlive())//checks the last node in the list
        {
            i++;//add one to the number alive
        }
        
        return i;//returns i, the number of alive NPCs on that team
    }
    
}



NPC* Team::at(int i)
{
    Node* curr = head;
    int j = 0;
    if(i <= size())
    {
        while(j <= i-1)
        {
            j++;
            curr = (curr)->next;
        }
        
        return (curr->x);
    }
    else return NULL;
    
}