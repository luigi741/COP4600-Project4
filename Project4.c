//============================================================================
// Project4.cpp
// This file implements the different page replacement algorithms:
// FIFO, LRU, LFU, MFU, OPT
// By: Luis Castro, Kerby Lalime, Max Maurente
//============================================================================

#include "algorithms.h"

int main()
{
	printf("Hello World!\n");
	printf("Welcome to COP 4600 - Project 4.\n\n");
	
	int refString[17] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 6};
	int pageArr[3][17];

	int refSize = sizeof(refString) / sizeof(*refString);

	// Fill all values of array with 0
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 17; j++)
		{
			pageArr[i][j] = 0;
		}
	}

	// Call to First In, First Out
	//FIFO(pageArr, refString);

	// Call to Optimal Page Replacement
	//OPT(pageArr, refString);
	OPT(refString, refSize, pageArr);

	// Page table map after calling FIFO
	for (int i = 0; i < 17; i++)
	{
		printf(" %d", refString[i]);
	}
	printf("\n-----------------------------------");
	printf("\n");

	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 17; j++)
		{
			printf("|%d", pageArr[i][j]);
		}
		
		printf("|\n");
	}

	printf("\n");
	return 0;
}