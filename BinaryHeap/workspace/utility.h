/*******************************************************
* * * * This file contains the utility functions * * * *
********************************************************/
int readData( FILE *file_in, dataArray *input, int *k ) { // Reading and writing data
	if (1 != fscanf(file_in, "%lu", &input->size)) { 
		fprintf(stderr, "Unable to read the size.\n");
        return 0;
	}
	if (1 != fscanf(file_in, "%d", k)) { 
		fprintf(stderr, "Unable to read k.\n");
        return 0;
	}
	// add more if needed fscanf(file_in, "%type", variable);
	input->data = (int *)malloc( (input->size) * sizeof(int) );
	for ( unsigned long int i = 0; i < input->size; ++i){
		if (1 != fscanf(file_in, "%d", &input->data[i])) {
            fprintf(stderr, "Unable to read the number at the position #%lu.\n", i);
            return 0;
		}
	}
	return 1;
}
void loadFile(int argc, char **argv, FILE *file_input, dataArray *input, int *k){
		if (argc > 2) {	fprintf(stderr, "Error! -> Usage: %s [file]\n", argv[0]);
			exit(EXIT_FAILURE);
		}else if ( argc > 1 ){ file_input = fopen(argv[1], "r"); 
			if(file_input==NULL){ printf("Error opening the file.\n");
				exit(EXIT_FAILURE); }
		} else { fprintf(stderr, "Error! -> Usage: %s [file]\n", argv[0]);
			exit(EXIT_FAILURE);}
		if(!readData (file_input, input, k)){ printf("Error reading the file.\n"); 
			exit(EXIT_FAILURE); 
		}
		input->length = input->size + 5;
		fclose(file_input);
}
void printData(dataArray arr) {
		printf("\n");
        for( int i=0; i < arr.size; ++i)
		printf("%d ", arr.data[i]);
		printf("\n");
    }
void printArray(int arr[],int size){
	for( int i=0; i < size; ++i)
		printf("%d ", arr[i]);

};
void printRange(dataArray *arr,unsigned long int start,unsigned long int end){
		printf("\n");
		if (end < arr->size) for( unsigned long int i = start; i < end; ++i) printf("%d ", arr->data[i]);
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
void cut(dataArray arr,rezStruct *rez, unsigned long int k){
	for (unsigned long int i = 0; i < k; i++){
		rez->data[i]= arr.data[i];
	}
	arr.size = arr.size - k;
}
void printDeleted(dataArray arr, unsigned long int k){
	for (unsigned long int i = 0; i < k; i++){
		printf("%d ",arr.data[arr.size-i-1]);
	}
}
void initResult(unsigned long int size){
	extern rezStruct result;
	result.size = size;
	result.data = (int*)malloc(size * sizeof(int));
}
void printResult(unsigned long int reqSize){
	extern rezStruct result;
	if(result.size < reqSize){
		printf("\nERROR! Required size for Result is bigger than its actual size\n");
		exit(EXIT_FAILURE);
	}
	printf("\n");
	for (unsigned long int i = 0; i < reqSize; i++){
		printf("%d ",result.data[i]);
	}printf("\n");
};
void PRINTING(dataArray workspace, double time_ms, unsigned long int k, bool pd, bool pr){
	printf("\nThe time for the algorithm is %f ms.\n", time_ms);
	printf("Number of swaps: %lu ",workspace.swaps); 
	if (pd == true) { printData(workspace); }
	if (pr == true) { printf("\nThe removed k elements are: "); printResult(k); }
}