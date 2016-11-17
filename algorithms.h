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

void FIFO(int refString[], int refSize, int pageArr[3][17])
{
    int i = 0; //used to iterate through refString
    int index = 0; // 
    int FIFOcount = 0;
    int missCount = 0;
    int buffer[3] = {0, 0, 0}; // holds copy of column
    int bufCount[3] = {0, 0, 0}; //holds how far back each element in column is 
    int size = refSize;

    int bufferSize = sizeof(buffer) / sizeof(*buffer);

    //printf("Size of refString: %d\n", refSize);
    //printf("Size of buffer: %d\n\n", bufferSize);
    printf("FIFO Page Replacement\n\n");

    // int i refers to refString[i]
    while (i < size)
    {
        //Check next column for miss or hit
        for (int j = 0; j < 3; j++)
        {
            if (buffer[j] == refString[i])
            {
                FIFOcount++; //page hit
            }
        }


        // Page hit, so repeat the previous column
        if (FIFOcount >= 1)
        {   
            for (int h = 0; h < 3; h++)
            {
                pageArr[h][i] = buffer[h];
            }
            //printf("PAGE HIT\n");
            
            FIFOcount = 0;
        }

        // Else, page miss
        else if (FIFOcount == 0)
        {
            //printf("i = %d\n", i);
            //int biggestIndex holds index of biggest in buffer
            //stands for first one in
            int biggest = 0;
            int biggestIndex;   

            // Get a count for each element in the column
            // pick the furthest on back.
            for (int l = 0; l < 3; l++)
            {
                
                //Walk backwards, count for each element
                //Put counts in buffCount
                int x = i; // to iterate back through

                while(buffer[l] == pageArr[l][x-1])
                {
                    bufCount[l]++;
                    if(bufCount[l] > biggest)
                    {
                        biggestIndex = l;
                        biggest = bufCount[l];
                    }
                    
                    if(x > 0)
                    {
                        x--;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(bufCount[l] > biggest)
                {
                    biggestIndex = l;
                    biggest = bufCount[l];
                }       
            }

            if(i == 0)
            {
                biggestIndex = 0;
            }
            else if(i == 1)
            {
                biggestIndex = 1;
            }
            else if(i == 2)
            {
                biggestIndex = 2;
            }

            biggest = 0;
            buffer[biggestIndex] = refString[i];

            // Update pageArray
            // Wipe bufCount
            //printf("**************\n");
            for (int j = 0; j < 3; j++)
            {
                pageArr[j][i] = buffer[j];
                //printf("buffer[%d] : %d\n", j, buffer[j]);
                bufCount[j] = 0;
            }
            missCount++;
            //printf("PAGE MISS\n");
        }

        FIFOcount = 0;
        i++;
    }
}

void OPT(int refString[], int refSize, int pageArr[3][17])
{
    int i = 0; //used to iterate through refString
    int index = 0; // 
    int OPTcount = 0;
    int missCount = 0;
    int buffer[3] = {0, 0, 0}; // holds copy of column
    int bufCount[3] = {0, 0, 0}; //holds how far back each element in column is 
    int size = refSize;

    int bufferSize = sizeof(buffer) / sizeof(*buffer);

    //printf("Size of refString: %d\n", refSize);
    //printf("Size of buffer: %d\n\n", bufferSize);
    printf("OPT Page Replacement\n\n");

    // int i refers to refString[i]
    while (i < size)
    {
        //Check next column for miss or hit
        for (int j = 0; j < 3; j++)
        {
            if (buffer[j] == refString[i])
            {
                OPTcount++; //page hit
            }
        }

        // Page hit, so repeat the previous column
        if (OPTcount >= 1)
        {   
            for (int h = 0; h < 3; h++)
            {
                pageArr[h][i] = buffer[h];
            }
            //printf("PAGE HIT\n");
            
            OPTcount = 0;
        }

        // Else, page miss
        else if (OPTcount == 0)
        {
            //printf("i = %d\n", i);
            //int biggestIndex holds index of biggest in buffer
            //stands for first one in
            int biggest = 0;
            int biggestIndex;   
            
            // Get a count for each element in the column
            // pick the furthest one foward
            for (int l = 0; l < 3; l++)
            {
                
                //Walk forwards, count for each element
                //Put counts in buffCount
                int x = i; // to iterate back through

                while(buffer[l] != refString[x+1])
                {
                    bufCount[l]++;
                    if(bufCount[l] > biggest)
                    {
                        biggestIndex = l;
                        biggest = bufCount[l];
                    }
                    
                    if(x < size)
                    {
                        x++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(bufCount[l] > biggest)
                {
                    //printf("bufCount[%d] : %d\n", l, bufCount[l]);
                    biggestIndex = l;
                    biggest = bufCount[l];
                }       
            }

            if(i == 0)
            {
                biggestIndex = 0;
            }
            else if(i == 1)
            {
                biggestIndex = 1;
            }
            else if(i == 2)
            {
                biggestIndex = 2;
            }

            biggest = 0;
            buffer[biggestIndex] = refString[i];

            // Update pageArray
            // Wipe bufCount
            //printf("**************\n");
            for (int j = 0; j < 3; j++)
            {
                pageArr[j][i] = buffer[j];
                //printf("buffer[%d] : %d\n", j, buffer[j]);
                //printf("bufCount[%d] : %d\n", j, bufCount[j]);
                bufCount[j] = 0;
            }
            missCount++;
            //printf("PAGE MISS\n");
        }

        OPTcount = 0;
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

	//printf("Size of refString: %d\n", refSize);
	//printf("Size of buffer: %d\n\n", bufferSize);
	printf("LRU Page Replacement\n");

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

int LFU(int refString[])
{
	printf("LFU Page Replacement\n");
	int frames = 3;
  	int numpages = 17;
  	int hit = 0;
  	int pagefault = 3;
	
  	int frame[17], array[17], time[17];
	int i, j, page, flag, k, minimum_time, temp;
  
  	//initialize the page table to -1
	for(i = 0; i < numpages; i++)
	{
		frame[i] = -1;
	}
	
	for(i = 0; i < 17; i++)
	{
		array[i] = 0;
	}
	
  	//lfu algorithm
  	for(i = 0; i < numpages; i++)
  	{
    	array[refString[i]]++;
    	time[refString[i]] = i;     //updates time spent in table for the current reference string element
    	flag = 1;
    	k = frame[0];
    	for(j = 0; j < frames; j++)
    	{ 
      		if(frame[j] == -1 || frame[j] == refString[i])  //compares reference string element to value of current page position
      		{
        		if(frame[j] != -1)    //checks if page is already in the table
        		{
            			hit++;   //increment hit count
        		}
        		flag = 0;
        		frame[j] = refString[i];    //places string element into page table
        		break;
      		}
      		
      		if(array[k] > array[frame[j]])
      		{
        		k = frame[j];
      		}
    	}
    	
    	if(flag)    //there is a page fault if true
    	{
      		pagefault++;
            minimum_time = 17;
      		for(j = 0; j < frames; j++) //determines which page has been least frequently used
      		{
        		if(array[frame[j]] == array[k] && time[frame[j]] < minimum_time)
        		{
        			temp = j;
        			minimum_time = time[frame[j]];   //updates minimum time spent in table
        		}
      		}
      		array[frame[temp]] = 0;
      		frame[temp] = refString[i];
    	}
    	
    	for(j = 0; j < frames; j++)     //prints the page table row by row
		{
      		printf("|%d\t", frame[j]);
    	}
    	
    	printf("\n");
  	}
  	
  	printf("LFU Hits:\t%d\n", hit);               //prints the number of successful hits
    printf("LFU Page Faults: %d\n", pagefault);      //prints the number of page faults
  	return 0;
}

#endif