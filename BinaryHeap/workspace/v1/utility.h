/*******************************************************
* * * * This file contains the utility functions * * * *
********************************************************/

void read_data( FILE *datain, int **dataout, int *n, int *k ) { // Reading and writing data
	int *data;
	fscanf(datain, "%d", n);
	fscanf(datain, "%d", k);
	*dataout = (int *)malloc( (*n) * sizeof(int) );
	data=*dataout;
	
	for ( int i=0; i< *n; ++i, ++data )
		fscanf( datain, "%d", data );
}
void print_data(int *tablou, int size) {
		printf("\n");
        for( int i=0; i<size; ++i)
		printf( "%d ", tablou[i] );
		printf("\n");
    }
void display_tree(int *tablou, int size){
	printf("\n");
	int nrLines = 3, elem = 0;

	for(int i = 1; i<=nrLines; i++){
		for(int j = 0; j < nrLines - i; j++){
			printf(" ");
		}
		for(int k = 2*i-1; k > 0; k--){
			printf(" %d ", tablou[elem]);
			elem++;
		}
		printf("\n");
	}
}
void copyArray (int *copyFrom, int *duplicate, int size){
	for(int i = 0; i < size; i++){
		duplicate[i] = copyFrom[i];
	}
}