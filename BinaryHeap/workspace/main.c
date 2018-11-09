#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
/*********************************************************
 * * * * * * * Data Read and Print Functions * * * * * * *
 *********************************************************/
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
/**********************************************************
 * * * * * * * * * * * Sort Functions * * * * * * * * * * *
 **********************************************************/
void swap(int *item_1, int *item_2){ // same as Permut()
    int temp = *item_1; 
    *item_1 = *item_2; 
    *item_2 = temp; 
} 
void bubbleSortFor (int *data, int size) { 
   for (int i = 0; i < size-1; i++){
       for (int j = 0; j < size-i-1; j++){
           if (data[j] > data[j+1]){
              swap(&data[j], &data[j+1]);
		   }
	   }
   }
}
void bubbleSortWhile (int *data, int range){ // optimized
	int i, j;
	bool swapped = true;
	while ( swapped == true ){
		swapped = false;
		for (i = 0; i < range - 1; i++ ){
			if (data[i] > data[i+1] ){
				swap(&data[i], &data[i+1]);
				swapped = true;
			}
		}
		range =  range - 1;
	}
}
/*********************************************************
 * * * * * * * * * Binary Heap Functions * * * * * * * * *
 *********************************************************/
int PARENT(int i) {
	return (i-1)/2; // the floor((i-1)/2) lives on, but does extra work :(
}
int LEFTchild(int i){
	return 2*i + 1;
}
int RIGHTchild(int i){
	return 2*i + 2;
}
void Permut(int *item_1, int *item_2){ //verified - same as swap()
		int temp = *item_1; 
		*item_1 = *item_2; 
		*item_2 = temp; 
}
void PercolateUp(int *data, int size, int current){	//verified
	int parent = PARENT(current);
	while (parent >= 0 && data[parent] < data[current]){
		Permut(&data[current],&data[parent]);//same as swap
		current = parent;
		parent = PARENT(current);
	}
}
void PercolateDown(int *data, int size, int current){ //verified
	int left = LEFTchild(current), 
		right = RIGHTchild(current), 
		curr_largest = current;
	if ( (left < size) && ( data[current] < data[left] ) ){
		curr_largest = left;
	}
	if ( (right < size) && ( data[curr_largest] < data[right] ) ){
		curr_largest = right;
	}
	if (curr_largest != current){
		Permut(&data[current], &data[curr_largest]); //same as swap
		PercolateDown(data, size, curr_largest);
	}
}
void BuildMaximalHeap(int *data, int size, int lenMax){ //verified
	printf("\nBuilding maximal heap\n");
	if (size > 0 && size <= lenMax) {
		for (int i = size / 2; i >= 0; i--){
			PercolateDown(data, size, i);
		}
	}
	else printf("\nError! Size of your heap is 0!");
}
void BuildMinimalHeap(){ // To be completed

}
int REMOVE(int *data, int *size){//printf("\nRemoving root element %d from heap\n",data[0]);
	int removed = data[0];
	data[0] = data[*size-1];
	*size = *size - 1;
	PercolateDown(data,*size,0);
	return removed;
}
void ADD(int *data, int *size, int length, int element){//printf("\nAdding element %d to the heap\n",element);
	if ( *size < length){
		data[*size] = element;
		*size = *size + 1;
		PercolateUp(data,*size,(*size-1));
	}
}
int bulk_REMOVE(int *data, int *size, int times){
	for (int i = 0; i < times; i++){
			REMOVE(data, size);
		}
}
/************************************************************
 * * * * * * * * * * * * Main Program * * * * * * * * * * * *
 ************************************************************/
int main( int argc, char **argv ) {
	int *worspace_data,*heapData, id_size, h_size, nh_size = 0,
		s_size, lenMax, k, addNR, delNR; 
	// lenMax is the maximum size the data can have
	bool read_from_file = true;
	double time_ms;
	clock_t duration;
	FILE *file_in;

	printf("\n!!!!!! Read From File = %d !!!!!!\n",read_from_file);
	////////////////////////////////////////////////////////////////
	
	if (read_from_file) { // Reading data from file, and printing it
		if ( argc > 1 )
			file_in = fopen(argv[1], "r");
		else
			file_in = stdin;	
		read_data( file_in, &worspace_data, &id_size, &k );
		// Displaying the read data
		printf("\nProgram read this data from your file:");
		print_data(worspace_data, id_size);
	}////////////////////////////////////////////////////////////////
	if (read_from_file){ // Functions to modify the data loaded from file
		heapData = worspace_data;
		h_size = id_size; s_size = id_size; lenMax = id_size + 5;
		int unsortedData[lenMax], sortedData[lenMax], newHeap[lenMax];
		copyArray(worspace_data, sortedData, id_size);
		//copyArray(worspace_data, unsortedData, id_size);

		// ### Building the Maximal Heap from file ###
		duration = clock(); // Initialising time 
		BuildMaximalHeap(heapData, h_size, lenMax);

		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;

		printf("The built heap is:"); print_data(heapData,h_size);
		printf("The time for building the heap is %f:\n", time_ms);

		// ### Building the Maximal Heap with ADD ###
		addNR = 13 ; duration = clock(); // Initialising time 
		for (int i = 0; i < addNR; i++){
			ADD(newHeap,&nh_size,lenMax,worspace_data[i]);
		}
		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;

		printf("\nThe new Heap is is:"); print_data(newHeap,nh_size);
		printf("The time for the new heap to be built is %f:\n", time_ms);

		// ### Sorting with bubbleSort() ###
		duration = clock(); // Initialising time
		bubbleSortWhile(sortedData,s_size);

		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000 ;

		printf("\nThe sorted data is:"); print_data(sortedData,s_size);
		printf("The time for the data to be sorted is %f:\n", time_ms);

		// ### Removing k items from heap ###
		delNR = 3; duration = clock(); // initialising time
		bulk_REMOVE(heapData, &h_size, delNR);

		duration = clock() - duration; time_ms = duration / (double) CLOCKS_PER_SEC * 1000;

		printf("\nThe resulted heap after deleting %d items is:", delNR); print_data(heapData,h_size);
		printf("The time for the removal of %d elem is %f:\n", delNR, time_ms);
		
		// Modifying the maximal Heap

		//REMOVE(file_data, &cd_size);
		//ADD(file_data,&cd_size,lenMax,AddedElement);

		//display_tree(data,cd_size); // RIP
		//free(file_data);
	}
	else { // Manually doing whatever without having a file loaded
		lenMax = 15; //whatever number is required
		h_size = 0;
		static int custom_data[20] = { 0 };
		worspace_data = custom_data;
		ADD(worspace_data, &h_size,lenMax,custom_data[1]);
		ADD(worspace_data, &h_size,lenMax,custom_data[2]);
		ADD(worspace_data, &h_size,lenMax,custom_data[3]);
		ADD(worspace_data, &h_size,lenMax,custom_data[4]);
		ADD(worspace_data, &h_size,lenMax,custom_data[5]);
		print_data(worspace_data,h_size);
	}

	
    //int n = sizeof(arr)/sizeof(arr[0]); 
/*		// Removing elements
		for (int i = 0; i < delNR; i++){
			REMOVE(worspace_data, &cd_size);
		}
	}*/

	return 0;
}