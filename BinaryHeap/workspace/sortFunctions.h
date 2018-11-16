/*******************************************************
* * * * This file contains the functions sorting * * * *
* * * * * * * Min to Max and Reversed sort * * * * * * * 
********************************************************/
void bubbleSort (dataArray *arr, unsigned long int k) { //O(n^2)
    extern rezStruct result;
    bool flag = false;
    int times = 0;
    for (unsigned long int i = 0; i < k; i++){
        flag = false;
        for (unsigned long int j = 0; j < arr->size-i-1; j++){
            if ( (arr->priority == max) && (arr->data[j] > arr->data[j+1]) 
                || (arr->priority == min) && (arr->data[j] < arr->data[j+1]) ){
                swap(&arr->data[j], &arr->data[j+1],&arr->swaps);
                flag = true;
            }
        }
        if (k<=result.size) result.data[i] = arr->data[arr->size -i-1];
        if(!flag) break;
        times++;
   }
   printf("Times the loop was repeated %d",times);
}
void reverseBubbleSort (dataArray *arr, unsigned long int k) { //O(n^2)
    extern rezStruct result;
    bool flag = false;
    for (unsigned long int i = 0; i < k-1; i++){
        for (unsigned long int j = 0; j < arr->size-i-1; j++){
            if ( (arr->priority == max) && (arr->data[j] < arr->data[j+1]) 
                || (arr->priority == min) && (arr->data[j] > arr->data[j+1]) ){
                swap(&arr->data[j], &arr->data[j+1],&arr->swaps);
                flag = true;
            }
        }
        result.data[i] = arr->data[arr->size -i-1];
        if(!flag) break;
   }
}
int choosePivot (int i,int j ) {
    return ( (i+j) / 2 );
}
void quickSort (dataArray *arr,int low,int high) {//O(n^2)
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
                || (arr->priority == min ) && (arr->data[j] < key) && (j >= low) ) 
                { j--; }
            if( i < j) { swap(&arr->data[i],&arr->data[j],&arr->swaps); }
        }
        swap(&arr->data[low],&arr->data[j],&arr->swaps);
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
    }
}

void heapSort (dataArray *arr) {//O(n log(n)) = O(n) + O (n log n)
    BuildHeap(arr);
    for (int i = 0; i < arr->size; i++) {
        swap(&arr->data[arr->size-i-1],&arr->data[0],&arr->swaps);
        PercolateDown(arr, arr->size-i-1, 0);
    }
}
void heapSortRemove(dataArray *input, dataArray *output, unsigned long int k){//partialHeapSort
    extern rezStruct result;
    BuildHeap(input); output->size = k;
    for (unsigned long int i = 0; i < k; i++){
        output->data[k-i-1] = REMOVE(input,0); //ascending order
    } output->swaps = input->swaps;
}
void merge(dataArray *arr, unsigned long int left,unsigned long int middle,unsigned long int right){
    unsigned long int i,j,k, 
        sizeL = middle -left +1, 
        sizeR = right - middle;
    int L[sizeL], R[sizeR];
    for (i = 0; i< sizeL; i++){
        L[i] = arr->data[left +i];
    }
    for(j = 0; j < sizeR; j++){
        R[j] = arr->data[middle +j +1];
    }
    i = 0; j = 0; k = left;

    while(i < sizeL && j < sizeR){
        if(L[i] <= R[j]){
            arr->data[k] = L[i]; i++;
        }
        else {
            arr->data[k] = R[j]; j++; 
        }
        k++;
    }
    while(i < sizeL){ arr->data[k] = L[i]; i++; k++; }
    while(j < sizeR){ arr->data[k] = R[j]; j++; k++; }
}
void mergeSort (dataArray *arr, unsigned long int left, unsigned long int right) {//O(n log n)
    if(left < right){
        unsigned long int middle = left + (right-left)/2;
        mergeSort(arr,left,middle);
        mergeSort(arr,middle+1,right);
        merge(arr, left, middle, right);
    }
}
int qomparator(const void * a, const void * b) {
		return ( *(int*)a - *(int*)b );
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