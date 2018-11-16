#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char **argv ) {
   	FILE *outputFile;
	unsigned long int size,k;
	int generated;
	if ( argc > 1 )	{
		printf("This program fills a file with random numbers in the following format:\nsize k\nnr.1 nr.2 nr.3 nr.4 nr.5 ... nr.size\nEnter your choices:\n");
		printf("size = ");scanf("%lu",&size);
		printf("k = ");scanf("%lu",&k);
		srand(time(NULL));
		outputFile = fopen(argv[1], "w+");
		fprintf(outputFile, "%lu %lu\n", size, k);
		for (int i = 0; i<size; i++){
			generated = rand() % size;
			fprintf(outputFile, "%d ", generated);}
		fclose(outputFile);
	}
	else {fprintf(stderr, "Error! -> Usage: %s [file]\n", argv[0]);
		exit(EXIT_FAILURE);}
	return 0;
}
