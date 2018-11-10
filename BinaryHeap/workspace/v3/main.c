#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "definition.h"
#include "utility.h"
#include "sortFunctions.h"
#include "binaryHeap.h"
/************************************************************
 * * * * * * * * * * * * Main Program * * * * * * * * * * * *
 ************************************************************/
int main( int argc, char **argv ) {
	mydata input;
	input.priority = max;
	bool read_from_file = true;
	unsigned int k;
	double time_ms,t1,t2,t3,t4;
	clock_t duration;
	FILE *file_input;


	if (read_from_file) { // Reading data from file, and printing it
		loadFile(argc, argv, file_input, &input, &k);

		dataArray workspace[input.length];
		fromDataToDataArray (&input, workspace); free(input.data);
		printf("\nProgram read this data from your file:");	printData(workspace);

		/*************************************************************
		 * * * * * * * * * * * * Modifyin data * * * * * * * * * * * *
		 *************************************************************/

		// Functions to modify the data loaded from file
		dataArray bheap[workspace->length], newADDheap[workspace->length], 
				  bSarray[workspace->length], qSarray[workspace->length];
		// Initializing the new dataArrays
		initializeEmpty(newADDheap,workspace);
		copyDataArray(bheap,workspace);		
		copyDataArray(bSarray,workspace);
		copyDataArray(qSarray,workspace);

		//printRange(bheap,1,5);
		BuildHeap(bheap);
		printf("heap:");printData(bheap);/*
		k_ADD(newADDheap,workspace,workspace->size);
		printf("newheap:"); printData(newADDheap);

		bubbleSort(bSarray);
		printf("bubblesort:");printData(bSarray);
		quickSort(qSarray, 0, qSarray->size - 1);
		printf("quickSort:");printData(qSarray);
		
		k_REMOVE(bheap,k);
		printf("\nremaining bheap:");printData(bheap);
		
		//RESET
		initializeEmpty(newADDheap,workspace);
		copyDataArray(bheap,workspace);		
		copyDataArray(bSarray,workspace);
		copyDataArray(qSarray,workspace);

		duration = clock(); 
		BuildHeap(bheap);
		k_REMOVE(bheap,bheap->size-2);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("The time for buildheap is %f:\n", time_ms);

		duration = clock(); 
		k_ADD(newADDheap,workspace,workspace->size);
		k_REMOVE(newADDheap,newADDheap->size-2);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("The time for ADDheap is %f:\n", time_ms);		

		duration = clock(); 
		bubbleSort(bSarray);
		k_REMOVE(bSarray,bSarray->size-2);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("The time for bubblesort is %f:\n", time_ms);
		
		//printf("h %u nh %u bs %u qs %u\nt1 = %f t2 = %f t3 = %f t4 = %f \n",h_size,nh_size,bS_size,qS_size,t1,t2,t3,t4);
		//display_tree(data,cd_size); // RIP
		//free(bheap->data); free(newADDheap->data);*/
	}
	else { printf("\n!!!!!! Warning !!! Read From File = %d !!!!!!\n",read_from_file);
	// Manually doing whatever without having a file loaded

	}

    //int n = sizeof(arr)/sizeof(arr[0]); 
	return 0;
}