/*******************************************************
* * * * This file contains the utility functions * * * *
********************************************************/
void readData( FILE *file_in, dataArray *input, int *k ) { // Reading and writing data
	fscanf(file_in, "%lu", &input->size);
	fscanf(file_in, "%d", k);
	// add more if needed fscanf(file_in, "%type", variable);
	input->data = (int *)malloc( (input->size) * sizeof(int) );
	for ( int i = 0; i < input->size; ++i){
		fscanf( file_in, "%d", &input->data[i] );
	}
}
void loadFile(int argc, char **argv, FILE *file_input, dataArray *input, int *k){
		if (argc > 2) {	fprintf(stderr, "Error!\nUsage: %s [file]\n", argv[0]);
			exit(EXIT_FAILURE);
		}
		if ( argc > 1 ){ file_input = fopen(argv[1], "r"); 
		} else file_input = stdin;
		readData (file_input, input, k); 
		input->length = input->size + 5;
}
void printData(dataArray arr) {
		printf("\n");
        for( int i=0; i < arr.size; ++i)
		printf("%d ", arr.data[i]);
		printf("\n");
    }
void printRange(dataArray *arr,unsigned long int start,unsigned long int end){
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
void copyListToDataArray (dataArray *copy, int initializer[], unsigned long int isize){
	if (isize > copy->length) {
		printf("\nWarning! The initializer array has a bigger size than allowed.\n");
		exit(EXIT_FAILURE);
	}
	else {
		for(int i = 0; i < isize; i++){
		copy->data[i] = initializer[i];
		}
		copy->size = isize;
	}
}
dataArray initDuplicateArrayFrom (dataArray copy){
	dataArray arr;
	arr.data = (int *)malloc( (copy.size) * sizeof(int) );
	for(int i = 0; i < copy.size; i++){
		arr.data[i] = copy.data[i];
	}
	arr.size = copy.size;
	arr.length = copy.length;
	arr.priority = copy.priority;
	arr.swaps = 0;
	return arr;
}
dataArray initEmptyArrayFromExisting(dataArray initializer){
	dataArray arr;
	arr.data = (int *)malloc( (initializer.size) * sizeof(int) );
	arr.size = 0;
	arr.length = initializer.length;
	arr.priority = initializer.priority;
	arr.swaps = 0;
	return arr;
}
void fillEmptyArrayFromExisting(dataArray *arr, dataArray initializer){
	arr->data = (int *)malloc( (initializer.size) * sizeof(int) );
	arr->size = initializer.size;
	arr->length = initializer.length;
	arr->priority = initializer.priority;
	arr->swaps = 0;
}
dataArray initInput(){
	dataArray arr;
	arr.size = 0; arr.length = 0; arr.swaps = 0; arr.priority = max;
	return arr;
}