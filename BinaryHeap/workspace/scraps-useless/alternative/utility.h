/*******************************************************
* * * * This file contains the utility functions * * * *
********************************************************/
void read_data( FILE *inputFile, int **fileData, init *fileInfo ) {
    fscanf(inputFile, "%lu", &fileInfo->size);
	fscanf(inputFile, "%lu", &fileInfo->k);
	*fileData = malloc(sizeof(int) * fileInfo->size);
	for ( unsigned long int i = 0; i < fileInfo->size; i++) {
		fscanf(inputFile, "%d", *fileData+i);
    }
}
void loadData(int argc, char **argv, FILE *inputFile, int **fileData, init *fileInfo){
    if ( argc > 1 )	{inputFile = fopen(argv[1], "r");}
	else inputFile = stdin;
    read_data( inputFile, fileData, fileInfo );
    fclose(inputFile);
}
void printData(dataArray arr) {
    printf("\n");
    for( int i=0; i < arr.size; ++i)
        printf("%d ", arr.data[i]);
    printf("\n");
}
void printArray(int *arr, unsigned long int size){
    printf("\n");
    for (int i = 0; i < size; i++){ printf("%d ",arr[i]); }
    printf("\n");
}
void initInfo (init *fileInfo){
    fileInfo->priority = max; 
    fileInfo->add = fileInfo->size;
    fileInfo->delete = fileInfo->k; 
    fileInfo->length = fileInfo->k +5;
}
dataArray initialize(init fileInfo){
    dataArray arr;
    arr.data = (int *)malloc( (fileInfo.size) * sizeof(int) );
	arr.size = 0;
	arr.length = fileInfo.length;
	arr.priority = fileInfo.priority;
	arr.swaps = 0;
    return arr;
}
void copyData(dataArray *arr, int *initializer, int size){
    for (unsigned long int i = 0; i < size; i++){
        arr->data[i] = initializer[i];
    }
    arr->size = size;
}
dataArray initDuplicate(dataArray *initializer){
    dataArray arr;
    arr.data = (int *)malloc(sizeof(int) * (initializer->size));
    for (unsigned long int i = 0; i < initializer->size; i++){
        arr.data[i] = initializer->data[i];
    }
	arr.size = initializer->size;
	arr.length = initializer->length;
	arr.priority = initializer->priority;
	arr.swaps = 0;
    return arr;
}