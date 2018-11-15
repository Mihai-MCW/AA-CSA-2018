#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "definition.h"
#include "utility.h"
#include "binaryHeap.h"

/************************************************************
 * * * * * * * * * * * * Main Program * * * * * * * * * * * *
 ************************************************************/
int main( int argc, char **argv ) {
	bool read_from_file = true;
    FILE *inputFile;
    int *input;
    init fileInfo;
    double time_ms,t1,t2,t3,t4;
    clock_t duration;

    if(read_from_file){
        loadData(argc, argv, inputFile, &input, &fileInfo);
        fileInfo.priority = max; fileInfo.add = fileInfo.size;
        fileInfo.length = fileInfo.size +5;

		int x=0;
		switch (x){
			case 1:{
				break;};
			case 2:{break;};
			case 3:{break;};
			case 4:{break;};
			case 5:{break;};
			default:{break;};
		}
	{

 /*
  
        dataArray workspace = initialize(fileInfo); //empty
        copyData(&workspace,input); free(input); //fill data in array
        dataArray bheap = initDuplicate(&workspace); //duplicate existing
        dataArray newADDheap = initialize(fileInfo);
        dataArray bSarray = initDuplicate(&workspace);
        dataArray qSarray = initDuplicate(&workspace);
        dataArray hSarray = initDuplicate(&workspace);

        duration = clock(); 
		BuildHeap(&bheap); 
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("\nThe time for buildheap is %f:\n", time_ms);
		printf("heap swaps: %lu ",bheap.swaps);// printData(bheap);
		

		duration = clock(); 
		k_ADD(&newADDheap,workspace,fileInfo.add);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("\nThe time for newADDheap is %f ms.\n", time_ms);
		printf("newADDheap swaps: %lu ",newADDheap.swaps);// printData(newADDheap);
		
		duration = clock(); 
		bubbleSort(&bSarray,fileInfo.sort);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("\nThe time for bubbleSort is %f ms.\n", time_ms);
		printf("bubbleSort swaps: %lu ",bSarray.swaps);// printData(bSarray);

		duration = clock(); 
		partialBubbleSort(&qSarray,fileInfo.add);
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
		k_REMOVE(&hSarray,fileInfo.delete);
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
		printf("\nThe time for heapSort is %f ms.\n", time_ms);
		printf("heapSort swaps: %lu ",hSarray.swaps);// printData(hSarray);     */
    }




    }
	return 0;
}