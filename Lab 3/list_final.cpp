#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <stdio.h>
#include <string.h>

using namespace std;//use standard namespace

struct Node
{
	
	string name;
	int quantity;
	double price;
	int position;
	Node* next;//pointer to the next node.
	
	
};

Node *m_head;
Node *m_tail;
int m_length;
int number = 0;

bool add(Node data);
bool remove_position(int position);
void print();

//main
int main()
{
	int action = 0;
	
	print();
	
	string choice;
	char *c;
	int length;
	while(action != 3)
	{
		cout << "Make a choice: (1) Add Item, (2) Remove item, (3) Exit" << endl;
		
		getline(cin, choice);
								
		c = &choice[0];
				
		action = atoi(c);
				
		if(action == 1)
		{
			Node newest;
			cout << "Enter new item: ";
			cin >> newest.name;
			cout << "Enter Quantity: ";
			cin >> newest.quantity;
			cout << "Enter unit price(EUR): ";
			cin >> newest.price;
			add(newest);
			cout << endl;
			print();
			cin.ignore (numeric_limits<streamsize>::max(), '\n');
		}
		else if(action == 2)
		{
			int pos;
			cout << "Which item do you want to delete? "; 
			cin >> pos;
			cin.ignore (numeric_limits<streamsize>::max(), '\n');
			if(pos <= number)
			{
				
				remove_position(pos);
				print();
			}
			else
			cout << endl << "Invalid: no item in that position." << endl << endl;
		}
		else if(action == 3)
		{
			cout << endl << "Bye" << endl << endl;
		}
		else
		{
			cout << endl << "Invalid: no such action." << endl << endl;
			
		}
	}
	
	return 0;
		
}

//define functions
double sum()
{
	double total = 0;
	Node *curr = m_head;
	while(curr != 0)
	{
		total = total + ((curr->price)*(curr->quantity));
		curr = curr -> next;
	}
	return total;
}


//prints list
void print()
{
	if (m_head != 0)
	{
		cout << "Your list contains " << number << " items for a total of " << sum() << " EUR" << endl;
		Node *curr = m_head;
		int i = 1;
		while(curr != 0)
		{
			cout << i++ << ") ";
			cout << curr -> name << ", "<< curr -> price << " EUR X " << curr -> quantity << ", Tot: " << (curr -> price )*(curr -> quantity) << " EUR" <<  endl;
			curr = curr -> next;
		}
		cout << endl;
	}
	else
	cout << endl <<"Your list is empty." << endl << endl;
}


//adds node to end of list
bool add(Node data)
{
	//create the new node
	Node *newNode = new Node;		//dynamically alicated, delete later
	*newNode = data;				//sets the payload to the data taken in by the f
	newNode ->next = 0;				//sets the next node to 0			      
									
   	if (m_head == NULL)
   	{
   		m_head = m_tail = newNode;
   		number = number +1;
   		return true;
   	}
   	else if (m_head->next == NULL)
   	{
		if (0 < strcasecmp(&(m_head->name[0]),&(newNode->name[0])))
		{
			newNode->next = m_head;
			m_head->next = NULL;
			m_tail = m_head;
			m_head = newNode;
		}
		else
		{
			m_head->next = newNode;
			m_tail = newNode;
		}
		number = number +1;
   		return true;
   	}
   	else
   	{
	    Node *curr = m_head;            // local iterator pointer
	    Node *prev = NULL;  			// local prev pointer
		
		while(curr->next != NULL)
		{
			if (0 < strcasecmp((&(curr->name[0])),(&(newNode->name[0]))))
			{
				if(curr == m_head)
				{
					newNode->next = m_head;
					m_head = newNode;
					number = number +1;
					return true;
					
				}
				else if(curr == m_tail)
				{
					m_tail->next = newNode;
					m_tail = newNode;
					number = number +1;
					return true;
				}
				else
				{
					newNode ->next = curr;
					prev->next = newNode;
					//newNode->next = next;
					number = number +1;
					return true;
				}
				
			}
			else
			{
				prev = curr;
	            curr = curr->next;
			}
		}
		m_tail->next = newNode;
		m_tail = newNode;
		newNode->next = NULL;
		number = number +1;
		return true;
	}
	return false;
}
	
//removes node, based on position
bool remove_position(int position)
{
	Node *curr = m_head;
	Node *prev = NULL;
	curr->position = 1;	
	while(curr->position <= position)
	{
		if(curr ->position == position)//we found the item to be deleted
		{
			if(curr == m_head)//special head
			{
				if(curr == m_tail)	//if last node, empty list
				{
					m_tail = NULL;
					m_head = NULL;
					number = 0;
					return true;
				}
				else				//if node is head then move head to next node

				{
					m_head = m_head ->next;

				}
			}
			else
			{
				prev->next = curr ->next; //"bypass" sets the node before the one to be deleted to go to the where the node being deleted would have
				
				if(curr == m_tail)//if the node being deleted is tail
				{
					m_tail = prev;
				}
			}
			
			delete curr;
			number= number - 1;
			
			return true;
		}
		
		if(curr != 0)
		{
			//if not the current element, iterate to the next one
			prev = curr;
			curr = curr ->next;
			curr->position = (1+(prev->position));
		}
	}
	
	return false;
}


