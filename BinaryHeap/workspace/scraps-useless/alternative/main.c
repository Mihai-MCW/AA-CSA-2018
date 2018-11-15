#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "definition.h"
#include "utility.h"
#include "binaryHeap.h"
#include "sortFunctions.h"
/************************************************************
 * * * * * * * * * * * * Main Program * * * * * * * * * * * *
 ************************************************************/
int main( int argc, char **argv ) {
    FILE *inputFile;
    int *result, choice;
    init fileInfo;
    double time_ms,t1,t2,t3,t4;
    clock_t duration;

    loadData(argc, argv, inputFile, &result, &fileInfo);
    initInfo(&fileInfo);
    
    dataArray input = initialize(fileInfo); //empty
    copyData(&input,result,fileInfo.size); free(result); //fill data in array
    dataArray workspace = initDuplicate(&input); //duplicate existing

    printf("1. BuildHeap + k_REMOVE | 2. ADDheap + k_REMOVE | 3. BubbleSort / Partial + Remove k \n4. QuickSort + Remove k | 5. HeapSort + k_REMOVE | 6. MergeSort + Remove k\n");
	choice = 2; //scanf("%d",&choice);
    printf("Your choice is %d\n",choice);

    int removed[fileInfo.k];
    switch (choice){
        case 1:{// BuildHeap and k_REMOVE
            duration = clock(); 
            BuildHeap(&workspace);
            k_REMOVE(&workspace, fileInfo.delete);
            duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
            printf("\nThe time for BuildHeap is %f:\n", time_ms);
            printf("BuildHeap swaps: %lu ",workspace.swaps); printData(workspace);
            printf("The removed k elem are:");//printArray(removed,fileInfo.delete);
            break;};
        case 2:{ // BuildHeap with ADD and k_REMOVE
            dataArray ADDheap = initialize(fileInfo);
            duration = clock(); 
            k_ADD(&ADDheap,workspace,fileInfo.add);printData(workspace);
            k_REMOVE(&ADDheap, fileInfo.delete);
            duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
            printf("\nThe time for Building Heap with k = %lu ADDs is %f:\n", fileInfo.add, time_ms);
            printf("ADDBuildHeap swaps: %lu ",ADDheap.swaps); printData(ADDheap);
            printf("The removed k elem are:");//printArray(removed,fileInfo.delete);
            break;};
        case 3:{//bubbleSort / Partial
            duration = clock(); 
            bubbleSort(&workspace, removed, fileInfo.delete);
            duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
            printf("\nThe time for bubbleSort for k = %lu is %f:\n", fileInfo.k,time_ms);
            printf("bubbleSort swaps: %lu ",workspace.swaps);// printData(workspace);
            printf("The removed k elem are:");printArray(removed,fileInfo.k);
            break;};
        case 4:{//quickSort
            duration = clock(); 
            quickSort(&workspace, 0, fileInfo.size -1);
            for (int i = 0; i < fileInfo.delete; i++){removed[i] = workspace.data[fileInfo.size-i-1];};
            duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;
            printf("\nThe time for quickSort is %f:\n", time_ms);
            printf("bubbleSort swaps: %lu ",workspace.swaps);// printData(workspace);
            printf("The removed k elem are:");printArray(removed,fileInfo.k);
            break;};
        case 5:{
            duration = clock(); 
            heapSort(&workspace);
            k_REMOVE(&workspace, fileInfo.delete);
            printf("\nThe time for quickSort is %f:\n", time_ms);
            printf("bubbleSort swaps: %lu ",workspace.swaps);// printData(workspace);
            printf("The removed k elem are:");printArray(removed,fileInfo.k);
            break;};
        default:{break;}
    }       

 	return 0;
}