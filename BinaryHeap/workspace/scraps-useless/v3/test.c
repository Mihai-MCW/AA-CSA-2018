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
    dataArray workspace[input.length];
    fromDataToDataArray (&input, workspace); free(input.data);
    //printf("\nProgram read this data from your file:");	printData(workspace);
    printf("%lu", workspace->size);
    dataArray bheap[workspace->length], newADDheap[workspace->length], 
				  bSarray[workspace->length], qSarray[workspace->length],
				  hSarray[workspace->length];
                  //dataArray que[workspace->length];
    copyDataArray(bheap,workspace);	
}