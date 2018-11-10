#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "utility.h"
#include "sortFunctions.h"
#include "maximalHeap.h"

/*********************************************************
 * * * * * * * Data Read and Print Functions * * * * * * *
 *********************************************************/

/************************************************************
 * * * * * * * * * * * * Main Program * * * * * * * * * * * *
 ************************************************************/
int main( int argc, char **argv ) {
	int *worspace_data,*heapData, id_size, h_size, nh_size = 0,
		s_size, lenMax, k, addNR, delNR; 
	// lenMax is the maximum size the data can have
	bool read_from_file = true;
	double time_ms;
	clock_t duration;
	FILE *file_in;

	printf("\n!!!!!! Read From File = %d !!!!!!\n",read_from_file);
	////////////////////////////////////////////////////////////////
	
	if (read_from_file) { // Reading data from file, and printing it
		if ( argc > 1 )
			file_in = fopen(argv[1], "r");
		else
			file_in = stdin;	
		read_data( file_in, &worspace_data, &id_size, &k );
		// Displaying the read data
		//printf("\nProgram read this data from your file:");	print_data(worspace_data, id_size);
	}////////////////////////////////////////////////////////////////
	if (read_from_file){ // Functions to modify the data loaded from file
		heapData = worspace_data;
		h_size = id_size; s_size = id_size; lenMax = id_size + 5;
		int unsortedData[lenMax], sortedData[lenMax], newHeap[lenMax];
		copyArray(worspace_data, sortedData, id_size);
		copyArray(worspace_data, unsortedData, id_size);

		// ### Building the Maximal Heap from file ###
		duration = clock(); // Initialising time 
		BuildHeap(heapData, h_size, lenMax);

		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;

		printf("The built heap is:"); print_data(heapData,h_size);
		printf("The time for building the heap is %f:\n", time_ms);

		// ### Building the Maximal Heap with ADD ###
		addNR = id_size ; duration = clock(); // Initialising time 
		for (int i = 0; i < addNR; i++){
			ADD(newHeap,&nh_size,lenMax,worspace_data[i]);
		}
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;

		//printf("\nThe new Heap is is:"); print_data(newHeap,nh_size);
		printf("The time for the new heap to be built is %f:\n", time_ms);
		
		// ### Sorting with bubbleSort() ###
		duration = clock(); // Initialising time
		bubbleSort(sortedData,s_size);

		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;

		//printf("\nThe sorted data is:"); print_data(sortedData,s_size);
		printf("The time for the data to be sorted (while) is %f:\n", time_ms);

		// ### Sorting with bubbleSort() ###
		duration = clock(); // Initialising time
		bubbleSort(unsortedData,s_size);

		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;

		//printf("\nThe sorted data is:"); print_data(unsortedData,s_size);
		printf("The time for the data to be sorted (for) is %f:\n", time_ms);


		// ### Removing k items from heap ###
		delNR = id_size-2; duration = clock(); // initialising time
		bulk_REMOVE(heapData, &h_size, delNR);

		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000;

		//printf("\nThe resulted heap after deleting %d items is:", delNR); print_data(heapData,h_size);
		printf("The time for the removal of %d elem is %f:\n", delNR, time_ms);
		
		// Modifying the maximal Heap

		//REMOVE(file_data, &cd_size);
		//ADD(file_data,&cd_size,lenMax,AddedElement);

		//display_tree(data,cd_size); // RIP
		//free(file_data);
	}
	else { // Manually doing whatever without having a file loaded
		lenMax = 15; //whatever number is required
		h_size = 0;
		static int custom_data[20] = { 0 };
		worspace_data = custom_data;
		ADD(worspace_data, &h_size,lenMax,custom_data[1]);
		ADD(worspace_data, &h_size,lenMax,custom_data[2]);
		ADD(worspace_data, &h_size,lenMax,custom_data[3]);
		ADD(worspace_data, &h_size,lenMax,custom_data[4]);
		ADD(worspace_data, &h_size,lenMax,custom_data[5]);
		print_data(worspace_data,h_size);
	}

	
    //int n = sizeof(arr)/sizeof(arr[0]); 
/*		// Removing elements
		for (int i = 0; i < delNR; i++){
			REMOVE(worspace_data, &cd_size);
		}
	}*/

	return 0;
}
