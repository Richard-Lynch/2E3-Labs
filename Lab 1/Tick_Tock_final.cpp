#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//Declare
void printBoard(int a[]); // prints board
void makeMove (int a[], int& Player, int& count);//asks for an input, checks input, edits array
void swap(int& Player); //swaps between players
void result(int a[], int& win, int count); //checks for a draw or a win

int main() 
{
	//declare
	int array[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //array
	
	int Win = 3; // (Win = 1 : DRAW)(Win = 2 : Someone Won)(Win = 3 : Keep playing) 
	
	int Count = 0; // Number of goes
	
	cout << "\nLet's play tick-tack-toe! \n";
	
	int player = 10; // plyaer 10 = x, player 11 = o
	
	printBoard(array);
	
	
	//while the win var = 3(Keep Playing)
	while(Win == 3)
	{
		makeMove(array, player, Count);
		result(array, Win, Count);
		printBoard(array);
	}
	
	
	swap(player);//winner
	if(Win == 2)//win
	{
		cout << endl << "Player ";
		if(player == 10)
		{cout << "X";}
		else
		{cout << "O";}
		
		cout << " Wins!!" << endl << endl;
	}
	else //draw
	{
		cout << endl << "Draw!";
		cout << endl << endl;
	}
	
	return 0;
}


//check win

void result(int a[], int& win, int count)
{
		if (a[1] == a[2] and a[2] == a[3]) 
		{win = 2;} // top row
		else if (a[4] == a[5] and a[5] == a[6]) 
		{win = 2;} // middle row
		else if (a[7] == a[8] and a[8] == a[9]) 
		{win = 2;} // bottom row
		else if (a[1] == a[4] and a[4] == a[7]) 
		{win = 2;} // left column
		else if (a[2] == a[5] and a[5] == a[8]) 
		{win = 2;} // middle column
		else if (a[3] == a[6] and a[6] == a[9]) 
		{win = 2;} // right column
		else if (a[1] == a[5] and a[5] == a[9]) 
		{win = 2;} //left diagonal
		else if (a[3] == a[5] and a[5] == a[7]) 
		{win = 2;} // right diagonal
		else if(count == 9)
		{win = 1;} // Draw
		else
		{win = 3;}
}
		
		

//prints board
void printBoard(int a[])
	{
		for(int i = 0; i <= 2; i++)
		{
			for(int n = 1; n <= 3; n++)
			{
				if(a[((i*3)+n)] == 10)
					cout << "X ";
				else if(a[((i*3)+n)] == 11)
					cout << "O ";
				else
					cout << a[((i*3)+n)] << " ";
			}
			cout << endl;
		}
	}
	
//ask for move
void makeMove (int a[], int& Player, int& count)
	{
		cout << endl << "Player ";
		
		if(Player == 10)
		cout << "X"; 		
		else cout << "O";
		
		cout << " , whats your move? ";

		int pos;
		cin >> pos;

		if((pos >= 1) and (pos <=9))
		{	       	if(a[pos] <= 9)
	       	{
	       		a[pos] = Player;
	       		swap(Player);
	       		count ++;
	       	}	  
	       	else
	       	{		
	       		cout << "Invalid Move!" << endl;
	       	}
		}
		else cout << "Invalid Move!" << endl;	
	}
	
//swaps players
void swap(int& Player)
{
  		if(Player == 10) Player = 11;
  		else Player = 10;
}



		
		
		
	
	