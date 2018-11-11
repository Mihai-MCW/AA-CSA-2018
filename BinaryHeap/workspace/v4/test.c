#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "definition.h"
#include "utility.h"


int main( int argc, char **argv ) {
	mydata input;
	input.priority = max;
	bool read_from_file = true;
	unsigned int k;
	double time_ms,t1,t2,t3,t4;
	clock_t duration;
	FILE *file_input;

    loadFile(argc, argv, file_input, &input, &k);
    dataArray workspace;
	workspace.data = (int *)malloc( (input.size) * sizeof(int) );
    //fromDataToDataArray (&input, workspace); free(input.data);
    //printf("\nProgram read this data from your file:");	printData(workspace);
    //dataArray bheap[workspace->length];
                  //dataArray que[workspace->length];
    
	int *test;
	test = (int *)malloc( (input.size) * sizeof(int) );
	for (int i = 0; i< input.size; i++){
		test[i] = input.data[i];
	}
	test[0]=444;
	for (int i = 0; i<input.size; i++){
		printf("%d ",input.data[i]);
	} printf("\n");
	for (int i = 0; i<input.size; i++){
		printf("%d ",test[i]);
	}
}