/*******************************************************
* * * * This file contains the utility functions * * * *
********************************************************/
void readData( FILE *datain, mydata *output, int *k ) { // Reading and writing data
	int *data;
	fscanf(datain, "%lu", &output->size);
	fscanf(datain, "%d", k);
	output->data = (int *)malloc( (output->size) * sizeof(int) );
	data=output->data;
	for ( int i=0; i< output->size; ++i, ++data )
		fscanf( datain, "%d", data );
}
void printData(dataArray *arr) {
		printf("\n");
        for( int i=0; i < arr->size; ++i)
		printf("%d ", arr->data[i]);
		printf("\n");
    }
void loadFile(int argc, char **argv, FILE *file_input, mydata *input, int *k){
		if (argc > 2) {	fprintf(stderr, "Error!\nUsage: %s [file]\n", argv[0]);
			exit(EXIT_FAILURE);
		}
		if ( argc > 1 ){ file_input = fopen(argv[1], "r"); 
		} else file_input = stdin;
		readData (file_input, input, k); input->length = input->size + 5;
}
void printRange(dataArray *arr,unsigned long start,unsigned long end){
		printf("\n");
		if (end < arr->size) for( int i = start; i < end; ++i) printf("%d ", arr->data[i]);
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
void fromDataToDataArray (mydata *dta, dataArray *arr){
	for(int i = 0; i < dta->size; i++){
		arr->data[i] = dta->data[i];
	}
	arr->size = dta->size;
	arr->length = dta->length;
	arr->priority = dta->priority;
}
void copyDataArray (dataArray *copy,dataArray *darr){
	for (int i = 0; i < darr->size; i++){
		copy->data[i] = darr->data[i];
	}
	copy->size = darr->size;
	copy->length = darr->length;
	copy->priority = darr->priority;	
}
void initializeEmpty(dataArray *arr,dataArray *initializer){
	arr->size = 0;
	arr->length = initializer->length;
	arr->priority = initializer->priority;
}