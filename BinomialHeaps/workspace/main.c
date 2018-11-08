#include <stdlib.h>
#include <stdio.h>
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
/**********************************************************
 * * * * * * * * * * * Sort Functions * * * * * * * * * * *
 **********************************************************/
int bubble_sort(int *data, int size){
    int temp;
    for( int i=0; i<size-1; ++i){
        if(data[i]<data[i+1]){
            temp = data[i];
            data[i] = data[i+1];
            data[i+1] = temp;
        }
    }
    return *data;
}
int checkSort(int *data, int *newData, int size){
    int sort=0;
    for( int i=0; i<size-1; ++i){
        if(data[i]!=newData[1]){
            sort = 0; break;
        }
        else sort = 1;
    }
    return sort;
};
/***********************************************************
 * * * * * * * * * Binomial Heap Functions * * * * * * * * *
 ***********************************************************/
int PARENT(int i) {
	return i/2;
}
int LEFTchild(int i){
	return 2*i + 1;
}
int RIGHTchild(int i){
	return 2*i + 2;
}
void Permut(int *data, int current, int curr_largest){ //verified
	int temp = data[current];
	data[current] = data[curr_largest];
	data[curr_largest] = temp;
}
void PercolateUp(int *data, int size, int current){	//verified
	int parent = PARENT(current);
	while (parent >= 0 && data[parent] < data[current]){
		Permut(data, current, parent);
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
		Permut(data, current, curr_largest);
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
int REMOVE(int *data, int *size){
	printf("\nRemoving root element %d from heap\n",data[0]);
	int removed = data[0];
	data[0] = data[*size-1];
	*size = *size - 1;
	PercolateDown(data,*size,0);
	return removed;
}
void ADD(int *data, int *size, int length, int element){ //verified
	printf("\nAdding element %d to the heap\n",element);
	if ( *size < length){
		data[*size] = element;
		*size = *size + 1;
		PercolateUp(data,*size,(*size-1));
	}
}
/************************************************************
 * * * * * * * * * * * * Main Program * * * * * * * * * * * *
 ************************************************************/
int main( int argc, char **argv ) {
	int *file_data,*worspace_data;
	int id_size, cd_size, lenMax, k; // cd_size is current data size // lenMax is the maximum size the data can have
	FILE *file_in;
	int s = 0, rf = 1; printf("\n!!!!!! rf = %d !!!!!!\n",rf);
	////////////////////////////////////////////////////////////////
	if (rf == 1 || rf == 11) { // Reading data from file, 
		if ( argc > 1 )
			file_in = fopen(argv[1], "r");
		else
			file_in = stdin;	
		read_data( file_in, &file_data, &id_size, &k );
		// Displaying the read data
		printf("\nProgram read this data from your file: \n");
		print_data(file_data, id_size);
	}
	////////////////////////////////////////////////////////////////
	if (rf == 1){/* Functions to modify the data loaded from file */
		// Automatically setting the max length of the data
		cd_size = id_size;
		lenMax = cd_size + 5;
		// Building the Maximal Heap
		BuildMaximalHeap(file_data, cd_size, lenMax);
		printf("\nThe built heap is:\n");
		print_data(file_data,cd_size);
		// Modifying the maximal Heap

		//REMOVE(file_data, &cd_size);
		//ADD(file_data,&cd_size,lenMax,AddedElement);

		// Printing the output
		printf("\nProgram result: \n");
		print_data(file_data,cd_size);
		//display_tree(data,cd_size); // RIP
		free(file_data);
	}
	else if (rf = 11){ // "Manually" building heap with add from file 
		lenMax = 15 + 5;
		cd_size = 0;
		int addNR = 5, delNR = 2;
		int array[lenMax];
		for (int i = 0; i < addNR; i++){
			ADD(worspace_data,&cd_size,lenMax,file_data[i]);
		}
		print_data(worspace_data,cd_size);
		// Removing elements
		for (int i = 0; i < delNR; i++){
			REMOVE(worspace_data, &cd_size);
		}
		// Printing the output
		printf("\nProgram result: \n");
		print_data(worspace_data,cd_size);
	}
	else { // Manually doing whatever
		lenMax = 15; //whatever number is required
		cd_size = 0;
		static int custom_data[20] = { 0 };
		worspace_data = custom_data;
		ADD(worspace_data,&cd_size,lenMax,custom_data[1]);
		ADD(worspace_data,&cd_size,lenMax,custom_data[2]);
		ADD(worspace_data,&cd_size,lenMax,custom_data[3]);
		ADD(worspace_data,&cd_size,lenMax,custom_data[4]);
		ADD(worspace_data,&cd_size,lenMax,custom_data[5]);
		print_data(worspace_data,cd_size);
	}
/* Prototype sort
	if (s = 1) {
		int temp, n, check = 0;
		while(check != n){
			check = 2;
			for( int i=0; i<n-1; ++i){
				if(file_data[i]<file_data[i+1]){
					temp = file_data[i];
					file_data[i] = file_data[i+1];
					file_data[i+1] = temp;
				}
				else check = check + 1;
			}
		}
		printf("Ordered Data: \n");
		print_data(file_data,n);
		int newData[n-k];
		for(int i=0;i<n-k;i++){
			newData[i]=file_data[i];
			
		}
	}
*/
	return 0;
}