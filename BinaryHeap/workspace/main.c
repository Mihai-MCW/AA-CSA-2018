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
rezStruct result;
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
		initResult(input.size);//k

		{ // Workspace 1
		int choice = 0;
		printf("Your choice is: ");scanf("%d",&choice);


		switch (choice){
			case 1:{// ex1 BubbleSort / Partial
				dataArray workspace = initDuplicateArrayFrom(input);
				duration = clock(); bubbleSort(&workspace,workspace.size);
				duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
				bool pd = false, pr = true; PRINTING(workspace, time_ms, k, pd, pr);
				free(workspace.data); break;}
			case 2:{//ex2 BuildHeap O(n) and k_REMOVE O(k log(n)) Floyd's method
				dataArray workspace = initDuplicateArrayFrom(input);
				duration = clock();
				BuildHeap(&workspace); printf("Built Heap");//printData(workspace);
				k_REMOVE(&workspace,k);
				duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
				bool pd = false, pr = true; PRINTING(workspace, time_ms, k, pd, pr);
				free(workspace.data); break;}
			case 3:{// BuildHeap with ADD O(n log(n)) and k_REMOVE O(k log(n)) Williams’ method O(n log n)
				dataArray workspace = initEmptyArrayFromExisting(input);
				duration = clock();
				k_ADD(&workspace,input,input.size); printf("Built Heap");// printData(workspace);
				k_REMOVE(&workspace,k);
				duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
				bool pd = false, pr = true; PRINTING(workspace, time_ms, k, pd, pr);
				free(workspace.data); break;}
			case 4:{//HeapSort basic
				int *result;
				dataArray workspace = initDuplicateArrayFrom(input);
				dataArray output = initDuplicateArrayFrom(input);
				duration = clock(); heapSort(&workspace);
				duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
				bool pd = false, pr = false; PRINTING(workspace, time_ms, k, pd, pr);
				printf("The removed k elem are:\n");printDeleted(workspace,k);
				free(workspace.data); break;}
			case 5:{//HeapSort with k_REMOVE
				int *result;
				dataArray workspace = initDuplicateArrayFrom(input);
				dataArray output = initEmptyArrayFromExisting(input);
				duration = clock(); heapSortRemove(&workspace,&output,workspace.size);
				duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
				bool pd = false, pr = false; PRINTING(output, time_ms, k, pd, pr);
				printf("The removed k elem are:\n");printDeleted(output,k);
				free(workspace.data); free(output.data); break;}	
			case 6:{// QuickSort
				dataArray workspace = initDuplicateArrayFrom(input);
				duration = clock(); 
				quickSort(&workspace, 0, workspace.size - 1);
				duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
				bool pd = false, pr = false; PRINTING(workspace, time_ms, k, pd, pr);
				printf("The removed k elem are:\n"); printDeleted(workspace,k);
				free(workspace.data); break;}
			case 7:{// mergeSort O(n log n)
				dataArray workspace = initDuplicateArrayFrom(input);
				duration = clock(); 
				mergeSort (&workspace, 0, workspace.size-1);
				duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
				bool pd = false, pr = false; PRINTING(workspace, time_ms, k, pd, pr);
				printf("The removed k elem are:\n"); printDeleted(workspace,k);
				free(workspace.data); break;}
			case 8:{ 
				dataArray workspace = initDuplicateArrayFrom(input);
				duration = clock();
				qsort(workspace.data,workspace.size,sizeof(int),qomparator);
				duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
				bool pd = false, pr = false; PRINTING(workspace, time_ms, k, pd, pr);
				printf("The removed k elem are:\n"); printDeleted(workspace,k);
				free(workspace.data); break;}
			default:{break;}
		}
		free(input.data); free(result.data);
		}
	}
	else { printf("\n!!!!!! Warning !!! Read From File = %d !!!!!!\n",read_from_file);
	// Manually doing whatever without having a file loaded

	}
	return 0;
}