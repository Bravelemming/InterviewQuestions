// An array of 8 cells exists.  their state can be either active or inactive.  each day, their state changes:
// if both neighors are either 0 or 1, that cell is 0.  otherwise the cell is 1.  
// all cells are updated 'at once.'  


//TO DO: fix output from pointers!  (dereferenced data)
#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

int* cellCompete(int* cells, int days)
{
	//hold updates
	int updatedCells[8];

	for (int i = 0; i < 8; i++) {

		//track neighbors
		int neighborOne;
		int neighborTwo;

		int current = cells[i];
		//out of bounds, no neighbor
		if (i < 0) { 
			neighborOne = NULL; 
		}
		else {
			neighborOne = cells[i - 1];
		};

		//out of bounds, no neighbor
		if (i >= 8) { 
			neighborTwo = NULL; 
		}
		else {
			neighborTwo = cells[i + 1];
		};

		//if cell doesn't have a neighbor
		if (neighborOne == NULL || neighborTwo == NULL) {

			current = 0;

		}
		//check both neighbors
		else {

			if (neighborOne == 0 && neighborTwo == 0 || neighborOne == 1 && neighborTwo == 1) {
				current = 0;
			}
			else {
				current = 1;
			};
		};

		//actual magic
		updatedCells[i] = current;


	}; //end for

	return updatedCells;
}


int main() {

	//start conditions
	int cells[8] = { 1, 0, 0, 0, 0, 1, 0, 0 };
	int day = 1;

	//outputs
	int* p; 

	//actual magic 
	p = cellCompete(cells, day) ;
	
	//output and check
	for (int i = 0; i < 8; i++) {
		cout << *(p + i) << endl;
	};

	//pause for VS console
	int wait;
	cin >> wait;

	return 0;
}


