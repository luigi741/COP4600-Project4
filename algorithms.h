//=====================================================================================
// algorithms.h
// This file contains the functions for the page replacement algorithms
// By: Luis Castro
//=====================================================================================

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
// Test
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
			// Check if one element in the column equals next page
			for (int k = 0; k < 3; k++)
			{
				if (buffer[k] == refString[i+1])
				{
					OPTcount++;
				}
			}

			// Page hit, so repeat the previous column
			if (OPTcount >= 1)
			{	
				for (int h = 0; h < 3; h++)
				{
					pageArr[h][i] = buffer[h];
				}
				OPTcount = 0;
				continue;
			}
			// Page fault, so look ahead at refString[]
			else if (OPTcount == 0)
			{
				for (int l = 0; l < 3; l++)
				{
					//while (buffer[j] != refString[l])
				}
				pageArr[j][i] = buffer[j];
			}

			OPTcount = 0;
		}
		// Increment i
		i++;
	}
}

#endif