//=====================================================================================
// algorithms.h
// This file contains the functions for the page replacement algorithms
// By: Luis Castro
//=====================================================================================

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void FIFO(int pageArr[3][17], int refString[])
{
	int buffer[3];

	int i = 0;
	int h = 0;

	int count1 = 0;
	int count2 = 0;
	int count3 = 0;

	int hitCount = 0;
	int faultCount = 0;

	for (int j = 0; j < 17; j++)
	{
		for (int k = h; k < 17; k++)
		{
			if ((k > 1) && (refString[k] == pageArr[i][k-1] || refString[k] == pageArr[i][k-1]
							|| refString[k] == pageArr[i][k-1]))
			{
				hitCount++;
				continue;
			}
			else
			{
				pageArr[i][k] = refString[j];
			}
		}

		i++;
		h++;

		if (i == 3)
		{
			i = 0;
		}

		faultCount++;
	}
}

void OPT(int refString[], int refSize, int pageArr[3][17])
{
	int i = 0;
	int index = 0;
	int OPTcount = 0;
	int buffer[3] = {0, 0, 0};
	int bufCount[3] = {0, 0, 0};
	int size = refSize;

	int bufferSize = sizeof(buffer) / sizeof(*buffer);

	printf("Size of refString: %d\n", refSize);
	printf("Size of buffer: %d\n\n", bufferSize);
	printf("Optimal Page Replacement\n\n");
	
	while (i < size)
	{
		buffer[i%3] = refString[i];

		for (int j = 0; j < 3; j++)
		{
			OPTcount = 0;

			// Check if one element in the column equals next page
			for (int k = 0; k < 3; k++)
			{
				if (buffer[k] == refString[i])
				{
					printf("Page hit at pageArr[%d][%d]\n", i, k);
					OPTcount++;
				}
			}

			// Page hit, so repeat the previous column
			if (OPTcount > 0)
			{	
				for (int h = 0; h < 3; h++)
				{
					pageArr[h][i] = buffer[h];
				}
				continue;
			}
			// Page fault, so look ahead at refString[]
			else if (OPTcount == 0)
			{
				for (int x = 0; x < 3; x++)
				{
					pageArr[j][i] = buffer[j];
				}
			}
		}
		i++;
	}
	printf("\n");
}

void OPT2(int refString[], int refSize, int pageArr[3][17])
{
	int i = 0;
	int index = 0;
	int OPTcount = 0;
	int buffer[3] = {0, 0, 0};
	int bufCount[3] = {0, 0, 0};
	int size = refSize;

	int bufferSize = sizeof(buffer) / sizeof(*buffer);

	printf("Size of refString: %d\n", refSize);
	printf("Size of buffer: %d\n\n", bufferSize);
	printf("Optimal Page Replacement\n\n");
	
	while (i < size)
	{
		OPTcount = 0;
		for (int j = 0; j < 3; j++)
		{
			if (buffer[j] == refString[i])
			{
				OPTcount++;
			}
		}

		if (OPTcount == 0)
		{
			buffer[i%3] = refString[i];

			for (int k = 0; k < 3; k++)
			{
				pageArr[k][i] = buffer[k];
			}
		}
		else if (OPTcount > 0)
		{
			for (int l = 0; l < 3; l++)
			{
				pageArr[l][i] = buffer[l];
			}
		}

		i++;
	}
}

void OPT3(int refString[], int refSize, int pageArr[3][17])
{
	int i = 0;
	int index = 0;
	int OPTcount = 0;
	int buffer[3] = {0, 0, 0};
	int bufCount[3] = {0, 0, 0};
	int size = refSize;

	int bufferSize = sizeof(buffer) / sizeof(*buffer);

	printf("Size of refString: %d\n", refSize);
	printf("Size of buffer: %d\n\n", bufferSize);
	printf("Optimal Page Replacement\n\n");
	
	while (i < size)
	{
		OPTcount = 0;
		for (int j = 0; j < 3; j++)
		{
			if (buffer[j] == refString[i])
			{
				OPTcount++;
			}
		}

		if (OPTcount == 0)
		{
			for (int m = 0; m < 3; m++)
			{
				for (int n = i; n < 17; n++)
				{
					if (buffer[m] != refString[n])
					{
						bufCount[m]++;
					}
				}
			}

			buffer[i%3] = refString[i];

			for (int k = 0; k < 3; k++)
			{
				pageArr[k][i] = buffer[k];
			}
		}
		else if (OPTcount > 0)
		{
			for (int l = 0; l < 3; l++)
			{
				pageArr[l][i] = buffer[l];
			}
		}

		i++;
	}
}

int LRU(int refString[], int refSize, int pageArr[3][17])
{
	int i = 0; //used to iterate through refString
	int index = 0; // 
	int LRUcount = 0;
	int missCount = 0;
	int buffer[3] = {0, 0, 0}; // holds copy of column
	int bufCount[3] = {0, 0, 0}; //holds how far back each element in column is 
	int size = refSize;

	int bufferSize = sizeof(buffer) / sizeof(*buffer);

	printf("Size of refString: %d\n", refSize);
	printf("Size of buffer: %d\n\n", bufferSize);
	printf("LRU Page Replacement\n\n");

	// int i refers to refString[i]
	while (i < size)
	{
		//Check next column for miss or hit
		for (int j = 0; j < 3; j++)
		{
			if (buffer[j] == refString[i])
			{
				LRUcount++; //page hit
			}
		}


		// Page hit, so repeat the previous column
		if (LRUcount >= 1)
		{	
			for (int h = 0; h < 3; h++)
			{
				pageArr[h][i] = buffer[h];
			}
			//printf("PAGE HIT\n");
			
			LRUcount = 0;
		}

		// Else, page miss
		else if (LRUcount == 0)
		{
			//int biggestIndex holds index of biggest in buffer
			//stands for least recently used
			int biggest = 0;
			int biggestIndex;	

			// Get a count for each element in the column
			// pick the furthest on back.
			for (int l = 0; l < 3; l++)
			{
				//Walk backwards, count for each element
				//Put counts in buffCount
				int x = i; // to iterate back through

				while(buffer[l] != refString[x])
				{
					bufCount[l]++;
					if(bufCount[l] > biggest)
					{
						biggestIndex = l;
						biggest = bufCount[l];
					}
					
					if(x>0)
					{
						x--;
					}
					else
					{
						break;
					}
				}	
			}
			biggest = 0;

			//Update pageArray and buffer

			buffer[biggestIndex] = refString[i];
			for (int j = 0; j < 3; j++)
			{
				pageArr[j][i] = buffer[j];
				bufCount[j] = 0;
			}

			//Reset buffCountfor the next iteration
			int bufCount[3] = {0, 0, 0};
			missCount++;
			//printf("PAGE MISS\n");
		}

		LRUcount = 0;
		i++;
	}

	return missCount;
}

#endif