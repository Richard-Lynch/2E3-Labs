#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

using namespace std;//use standard namespace

//Declares functions
void bubbleSort(int array[], int n) ; //sorts array with bubble
void selectionSort(int array[], int n) ; //sorts array with selection


int main(int argc, char *argv[])//argc is the the number of arguements, and the *argv[] holds these arguments
{
	if (argc != 2)//check for correct number of arguements
	{
		cout <<  endl << "Wrong number of arguments" << endl;
		cout << "Number of arguments: " << argc << endl;
		cout << "usage: ./sort type" << endl; 
		cout << "type: 1 (for bubble sort) or 2 (for selection sort)" << endl << endl; 		
		return 1;
	}
	
	int type = atoi(argv[1]);
		
	if((type < 1) or (type > 2))//checks for valid arguements
	{
		cout << endl << "Not a valid arguments" << endl;
		cout << "usage: ./sort type" << endl; 
		cout << "type: 1 (for bubble sort) or 2 (for selection sort)" << endl << endl; 		
		return 1;
	}
	else//if correct number and valid, main program
	{
		const int randomSize = 10000;//random array size of 1000
		int randomNumber[randomSize];//initilises array
		
		// sets seed for random numbers
		srand (time(NULL));
			
		//fills array
    	for(int i = 0; i < randomSize; i++)
    	{
      		randomNumber[i] = rand();
    	}
    	
		//Initial output
		cout << endl << "--------------------------------------" << endl;
		cout << "Before sorting" << endl;
		cout << "Array[  0]= " << randomNumber[0] << endl;
		cout << "Array[" << (randomSize -1) << "]= " << randomNumber[999] << endl << endl;
		
		if(type == 1)//checks if user selected bubble(1)
		{
			cout << "Sorting with bubble sort" << endl;
			clock_t tStart = clock(); // Records start time
			
			bubbleSort(randomNumber, randomSize);//runs bubbleSort on array
			
			// Prints time elapsed between tStart and tEnd
		}
		else//if not, uses selection
		{
			cout << "Sorting with selection sort" << endl;
			clock_t tStart = clock(); // Records start time
			
			selectionSort(randomNumber, randomSize);//runs selectionSort on array
			
			// Prints time elapsed between tStart and tEnd
		}
		
		//Final output
		cout << "After sorting" << endl;
		cout << "Array[  0]= " << randomNumber[0] << endl;
		cout << "Array[" << (randomSize -1) << "]= " << randomNumber[999] << endl;
		cout << "--------------------------------------" << endl << endl;
		
		
	}
			
	return 0;
		
}
		
		
void bubbleSort(int array[], int n) 
{ 
	bool swapped = true;
	
	{ 
		swapped = false;
		// already been moved to the right place 
		// bubble sort between 0 and n-j
		{
			{
				std::swap(array[i], array[i+1]);
			} 
		}
}
	

void selectionSort(int array[], int n) 
{
	for (int i = 0; i < n; ++i)
		// smallestIndex is the index of the smallest
		// element we've encountered so far.
		
		// (starting at startIndex+1)
			// our previously found smallest
				// This is the new smallest number for
			}
	}
		