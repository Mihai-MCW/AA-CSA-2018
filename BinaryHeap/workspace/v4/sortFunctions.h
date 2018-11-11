/*******************************************************
* * * * This file contains the functions sorting * * * *
* * * * * * * Min to Max and Reversed sort * * * * * * * 
********************************************************/
void bubbleSort (dataArray *arr) { //O(n^2)
   for (int i = 0; i < arr->size-1; i++){
       for (int j = 0; j < arr->size-i-1; j++){
           if ( (arr->priority == max) && (arr->data[j] > arr->data[j+1]) 
             || (arr->priority == min) && (arr->data[j] < arr->data[j+1]) ){
              swap(&arr->data[j], &arr->data[j+1],&arr->swaps);
		   }
	   }
   }
}
void partialBubbleSort (dataArray *arr, int partial){
    for (int i = 0; i < partial; i++){
       for (int j = 0; j < arr->size-i-1; j++){
           if ( (arr->priority == max) && (arr->data[j] > arr->data[j+1]) 
             || (arr->priority == min) && (arr->data[j] < arr->data[j+1]) ){
              swap(&arr->data[j], &arr->data[j+1],&arr->swaps);
		   }
	   }
   }
}
int choosePivot (int i,int j ) {
    return ( (i+j) / 2 );
}
void quickSort (dataArray *arr,int low,int high) {
    int key,i,j,pivot;
    if( low < high) {
        pivot = choosePivot(low, high);
        swap(&arr->data[low],&arr->data[pivot],&arr->swaps);
        key = arr->data[low];
        i = low + 1;
        j = high;
        while(i <= j) {
            while( (arr->priority == max ) && (arr->data[i] <= key) && (i <= high)
                || (arr->priority == min ) && (arr->data[i] >= key) && (i <= high) ) 
                { i++; }
            while( (arr->priority == max ) && (arr->data[j] > key) && (j >= low)
                || (arr->priority == min ) && (arr->data[j] > key) && (j >= low) ) 
                { j--; }
            if( i < j) { swap(&arr->data[i],&arr->data[j],&arr->swaps); }
        }
        swap(&arr->data[low],&arr->data[j],&arr->swaps);
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
    }
}

void heapSort (dataArray *arr) {
    BuildHeap(arr);
    for (int i = 0; i < arr->size; i++) {
        swap(&arr->data[arr->size-i-1],&arr->data[0],&arr->swaps);
        PercolateDownOPT(arr, arr->size-i-1, 0);
        //PercolateDown(arr, arr->size-i-1, 0);
    }
}
void mergeSort () {

}
/*******************************************************
* * * * * * * * * * Unused functions * * * * * * * * * *
********************************************************/
/*void bubbleSortWhile (int *data, int range){ // pretty much the same as the 'for' version
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
*/