//=====================================================================================
// algorithms.h
// This file contains the functions for the page replacement algorithms
// By: Luis Castro
//=====================================================================================

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>

int FIFO(int pageArr[3][17], int refString[])
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

	return pageArr;
}

int OPT(int pageArr[3][17], int refString[])
{
	int index = 0;
	int OPTcount = 0;

	for (int j = 0; j < 17; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			// Check to see if there's going to be a page hit
			
			for (int k = 0; k < 3; k++)
			{
				if (pageArr[i][k] == refString[j+1]) 
				{
					OPTcount++;
				}
			}

			// If there's a page hit, then repeat the previous column in array
			if (OPTcount >= 1 && j > 0) 
			{
				for (int i = 0; i < 3; i++)
				{
					pageArr[i][j] = pageArr[i][j-1];
				}
			}
			else if (OPTcount == 0)
			{
				pageArr[i][j] = refString[j];
			}
		}
	}

	return pageArr;
}

#endif

/* Notes for Iterating through

1. If at first element of map, take first page of refString
2. If at second element of map, take first through second page of refString
3. If at third element of map, take first through third element of refstring
4. If at fourth element, check:
	if (pageArr[0...2][3] == refString[3])
		Copy pageArr[0...2][3] into pageArr[0...2][4]
5. Repeat step 4 until last element of refString

*/