//============================================================================
// algorithms.h
// This file contains the functions for the page replacement algorithms
// By: Luis Castro
//============================================================================

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>

int FIFO(int pageArr[3][17], int refString[])
{
	int i = 0;
	int h = 0;

	int hitCount = 0;
	int faultCount = 0;
	int loopCount = 0;

	for (int j = 0; j < 17; j++)
	{
		for (int k = h; k < 17; k++)
		{
			if (pageArr[0][j] == refString[k] || pageArr[1][j] == refString[k] ||
				pageArr[2][j] == refString[k])
			{
				hitCount++;
				continue;
			}

		pageArr[i][k] = refString[j];
		}

		i++;
		h++;

		if (i == 3)
		{
			i = 0;
		}

		faultCount++;
		loopCount++;
	}

	printf("Hit count: %d\nFault count: %d\n", hitCount, faultCount);
	printf("Total loops: %d\n\n", loopCount);
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