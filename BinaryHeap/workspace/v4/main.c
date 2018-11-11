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

	if (read_from_file) { // Reading data from file, and printing it
		loadFile(argc, argv, file_input, &input, &k);
		//printf("\nProgram read this data from your file:");	printData(input);
		
		dataArray bheap = initDuplicateArrayFrom(input),
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
		printf("\nThe time for newADDheap is %f:\n", time_ms);
		printf("newADDheap swaps: %lu ",newADDheap.swaps);// printData(newADDheap);
		
		duration = clock(); 
		bubbleSort(&bSarray);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("\nThe time for bubbleSort is %f:\n", time_ms);
		printf("bubbleSort swaps: %lu ",bSarray.swaps);// printData(bSarray);

		duration = clock(); 
		quickSort(&qSarray, 0, qSarray.size - 1);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("\nThe time for quickSort is %f:\n", time_ms);
		printf("quickSort swaps: %lu ",qSarray.swaps);// printData(qSarray);

		duration = clock(); 
		heapSort(&hSarray);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("\nThe time for heapSort is %f:\n", time_ms);
		printf("heapSort swaps: %lu ",hSarray.swaps);// printData(hSarray);

	}
	else { printf("\n!!!!!! Warning !!! Read From File = %d !!!!!!\n",read_from_file);
	// Manually doing whatever without having a file loaded
	}

    //int n = sizeof(arr)/sizeof(arr[0]); 
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