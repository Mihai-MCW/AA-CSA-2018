#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "definition.h"
#include "utility.h"
#include "binaryHeap.h"
#include "sortFunctions.h"
/************************************************************
 * * * * * * * * * * * * Main Program * * * * * * * * * * * *
 ************************************************************/
int main( int argc, char **argv ) {
	dataArray input = initInput();
	input.priority = max;
	bool read_from_file = true;
	unsigned int k;
	double time_ms,t1,t2,t3,t4;
	clock_t duration;
	FILE *file_input;

	if (read_from_file) { // Reading data from file, and/or printing it
		loadFile(argc, argv, file_input, &input, &k);
		//printf("\nProgram read this data from your file:");	printData(input);
		{ // Workspace 1
/*

		int n = input.size, te;
		duration = clock(); 
		for (int c = 0 ; c < n - 1; c++)
		{
			for (int d = 0 ; d < n - c - 1; d++)
			{
			if (input.data[d] > input.data[d+1]) 
			{
				te       = input.data[d];
				input.data[d]   = input.data[d+1];
				input.data[d+1] = te;
			}
			}
		}
 duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
  printf("\nThe time for buildheap is %f:\n", time_ms);
		//printf("heap swaps: %lu ",input.swaps);// printData(bheap);
*/


		duration = clock(); 
		bs(input.data,input.size);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("\nThe time for buildheap is %f:\n", time_ms);
		printf("heap swaps: %lu ",input.swaps);// printData(bheap);

		/*dataArray bheap = initDuplicateArrayFrom(input),
				newADDheap = initEmptyArrayFromExisting(input),
				bSarray = initDuplicateArrayFrom(input),
				qSarray = initDuplicateArrayFrom(input),
				hSarray = initDuplicateArrayFrom(input);
		
		duration = clock(); 
		BuildHeap(&bheap); 
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("\nThe time for buildheap is %f:\n", time_ms);
		printf("heap swaps: %lu ",bheap.swaps);// printData(bheap);
		

		duration = clock(); 
		k_ADD(&newADDheap,input,input.size);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("\nThe time for newADDheap is %f ms.\n", time_ms);
		printf("newADDheap swaps: %lu ",newADDheap.swaps);// printData(newADDheap);
		
		duration = clock(); 
		bubbleSort(&bSarray);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("\nThe time for bubbleSort is %f ms.\n", time_ms);
		printf("bubbleSort swaps: %lu ",bSarray.swaps);// printData(bSarray);

		duration = clock(); 
		partialBubbleSort(&qSarray,2000);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("\nThe time for partialbubbleSort is %f ms.\n", time_ms);
		printf("partialbubbleSort swaps: %lu ",qSarray.swaps);//printData(qSarray);

		duration = clock(); 
		quickSort(&qSarray, 0, qSarray.size - 1);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("\nThe time for quickSort is %f ms.\n", time_ms);
		printf("quickSort swaps: %lu ",qSarray.swaps);// printData(qSarray);

		duration = clock(); 
		heapSort(&hSarray);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("\nThe time for heapSort is %f ms.\n", time_ms);
		printf("heapSort swaps: %lu ",hSarray.swaps);// printData(hSarray);

		duration = clock(); 
		k_REMOVE(&hSarray,k);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("\nThe time for heapSort is %f ms.\n", time_ms);
		printf("heapSort swaps: %lu ",hSarray.swaps);// printData(hSarray);
		
		free(bheap.data); free(newADDheap.data); free(bSarray.data); free(qSarray.data); free(hSarray.data);*/
		}

	}
	else { printf("\n!!!!!! Warning !!! Read From File = %d !!!!!!\n",read_from_file);
	// Manually doing whatever without having a file loaded

	}
	return 0;
}

		/* Partial Sort
		int partialS = 3, ex[] = {19, 1, 9, 7, 3, 10, 13, 15, 8, 1};
		unsigned long exSize = 10, exLength = exSize;
		priority_t exPriority = max;
		dataArray example[exSize]; 
		initializeDataWith(example,ex,exSize,exLength,exPriority);
		printData(example);
		partialBubbleSort(example,partialS);printData(example);
		*/

		/* Functions and variables
		workspace->data;
		workspace->size;
		workspace->length;
		workspace->priority; 
		dataArray array[workspace->size];
		copyDataArray(array,workspace);
		initializeEmpty(array,workspace);
		BuildHeap(array);
		ADD(array);
		REMOVE(array);
		k_ADD(array,workspace,input_size);
		k_REMOVE(array,remove_times);
		printRange(array,start,end);
		printData(array);
		double duration = clock(); duration = clock() - duration;
		time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		*/