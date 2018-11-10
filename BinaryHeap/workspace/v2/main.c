#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "utility.h"
#include "sortFunctions.h"
#include "maximalHeap.h"
/************************************************************
 * * * * * * * * * * * * Main Program * * * * * * * * * * * *
 ************************************************************/
int main( int argc, char **argv ) {
	unsigned int init_size, k;
	int *worspace_data; 
	// lenMax is the maximum size the data can have
	bool read_from_file = true;
	double time_ms,t1,t2,t3,t4;
	clock_t duration;
	FILE *file_in;
	
	if (read_from_file) { // Reading data from file, and printing it
		if (argc > 2) {
			fprintf(stderr, "Error!\nUsage: %s [file]\n", argv[0]);
			exit(EXIT_FAILURE);
		}
		if ( argc > 1 ){ file_in = fopen(argv[1], "r"); }
		else file_in = stdin;

		read_data( file_in, &worspace_data, &init_size, &k );
		// Displaying the read data
		//printf("\nProgram read this data from your file:");	print_data(worspace_data, id_size);
	}
	if (read_from_file){ // Functions to modify the data loaded from file
		unsigned int h_size = init_size, bS_size = init_size, qS_size = init_size,
					 nh_size = 0,
					 lenMax = init_size + 5,
					 addNR = init_size, delNR = k;
		int *heapData = worspace_data;
		int bSarray[lenMax], qSarray[lenMax], newADDheap[lenMax];
		copyArray(worspace_data, bSarray, bS_size);
		copyArray(worspace_data, qSarray, qS_size);

		// ##########################################
		// ## Building the Maximal Heap from file ##
		duration = clock(); // Initialising time 
		BuildHeap(heapData, h_size, lenMax);

		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		t2 = time_ms;
		//printf("The heap built from data is:"); print_data(heapData,h_size);
		printf("The time for building the heap is %f:\n", time_ms);

		// ########################################
		// ## Building the Maximal Heap with ADD ##
		duration = clock(); // Initialising time 
		for (int i = 0; i < addNR; i++){
			ADD(newADDheap,&nh_size,lenMax,worspace_data[i]);
		}
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		t3 = time_ms;
		//printf("\nThe Heap built by adding elem is:"); print_data(newADDheap,nh_size);
		printf("The time for the new heap to be built is %f:\n", time_ms);

		// ################################
		// ## Sorting with bubbleSort() ##
		duration = clock(); // Initialising time
		bubbleSort(bSarray,bS_size);

		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		t1 = time_ms;
		//printf("\nThe sorted data with bubbleSort is:"); print_data(bSarray,bS_size);
		printf("The time for the data to be sorted (while) is %f:\n", time_ms);

		// ###############################
		// ## Sorting with quickSort() ##
		duration = clock(); // Initialising time
		quickSort(qSarray,0,qS_size-1);

		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		t4 = time_ms;
		//printf("\nThe sorted data is:"); print_data(qSarray,qS_size);
		printf("The time for the data to be sorted (for) is %f:\n", time_ms);

		// ######################################################
		// ### Removing k biggest/smallest items from heapData ##
		duration = clock(); // initialising time
		k_REMOVE(heapData, &h_size, delNR);

		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000;
		t2 = t2 + time_ms;
		//printf("\nThe resulted heap after deleting %d items is:", delNR); print_data(heapData,h_size);
		printf("The time for the removal of %d elem is %f:\n", delNR, time_ms);
		
		// #######################################################
		// ## Removing k biggest/smallest items from newADDheap ##
		duration = clock(); // initialising time
		k_REMOVE(newADDheap, &nh_size, delNR);

		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000;
		t3 = t3 + time_ms;

		// ###########################################
		// ## Removing k biggest items from bSarray ##
		duration = clock(); // initialising time

		//bS_size = bS_size - delNR;
		
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000;
		t1 = t1 + time_ms;
		// Modifying the maximal Heap
		printf("h %u nh %u bs %u qs %u\nt1 = %f t2 = %f t3 = %f t4 = %f \n",h_size,nh_size,bS_size,qS_size,t1,t2,t3,t4);
		//display_tree(data,cd_size); // RIP
		free(worspace_data); free(heapData);
	}
	else { printf("\n!!!!!! Warning !!! Read From File = %d !!!!!!\n",read_from_file);
	// Manually doing whatever without having a file loaded
	/*	lenMax = 15; //whatever number is required
		h_size = 0;
		static int custom_data[20] = { 0 };
		worspace_data = custom_data;
		ADD(worspace_data, &h_size,lenMax,custom_data[1]);
		ADD(worspace_data, &h_size,lenMax,custom_data[2]);
		ADD(worspace_data, &h_size,lenMax,custom_data[3]);
		ADD(worspace_data, &h_size,lenMax,custom_data[4]);
		ADD(worspace_data, &h_size,lenMax,custom_data[5]);
		print_data(worspace_data,h_size);
*/	}

    //int n = sizeof(arr)/sizeof(arr[0]); 
	return 0;
}