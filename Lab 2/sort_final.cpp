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
						clock_t tEnd = clock(); // Records end time
			// Prints time elapsed between tStart and tEnd			cout << "TIME: " << (double)(tEnd - tStart)/CLOCKS_PER_SEC << endl << endl;
		}
		else//if not, uses selection
		{
			cout << "Sorting with selection sort" << endl;
			clock_t tStart = clock(); // Records start time
			
			selectionSort(randomNumber, randomSize);//runs selectionSort on array
						clock_t tEnd = clock(); // Records end time
			// Prints time elapsed between tStart and tEnd			cout << "TIME: " << (double)(tEnd - tStart)/CLOCKS_PER_SEC << endl << endl;
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
	bool swapped = true;	int j = 0;
	    // keep sorting only you had to swap	while (swapped) 
	{ 
		swapped = false;		j++;		// numbers from position n-j to n-1 have 
		// already been moved to the right place 
		// bubble sort between 0 and n-j		for (int i = 0; i < n - j; i++) 
		{		    // compare element i with the next			if (array[i] > array[i + 1]) 
			{				// swap them if they are not in the right order 
				std::swap(array[i], array[i+1]);				swapped = true;
			} 
		}	}
}
	

void selectionSort(int array[], int n) 
{	// Step through each element of the array 
	for (int i = 0; i < n; ++i)	{
		// smallestIndex is the index of the smallest
		// element we've encountered so far.		int smallestIndex = i;
				// Look for smallest element remaining in the array 
		// (starting at startIndex+1)		for (int j = i + 1; j < n; ++j)		{			// If the current element is smaller than 
			// our previously found smallest			if (array[j] < array[smallestIndex])			{
				// This is the new smallest number for				// this iteration				smallestIndex = j;
			}			// Swap our start element with our smallest element	        std::swap(array[i], array[smallestIndex]);	    }
	}}
		
