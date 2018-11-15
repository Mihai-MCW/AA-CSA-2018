/*******************************************************
* * * * This file contains the functions sorting * * * *
* * * * * * * Min to Max and Reversed sort * * * * * * * 
********************************************************/
void swap(int *item_1, int *item_2){ // same as Permut()
    int temp = *item_1; 
    *item_1 = *item_2; 
    *item_2 = temp; 
}
int choosePivot (int i,int j ) {
    return ( (i+j) / 2 );
}
void bubbleSort (int *data, int size) { 
   for (int i = 0; i < size-1; i++){
       for (int j = 0; j < size-i-1; j++){
           if (data[j] > data[j+1]){
              swap(&data[j], &data[j+1]);
		   }
	   }
   }
}
void reversedBubbleSort (int *data, int size) { 
   for (int i = 0; i < size-1; i++){
       for (int j = 0; j < size-i-1; j++){
           if (data[j] < data[j+1]){
              swap(&data[j], &data[j+1]);
		   }
	   }
   }
}
void quickSort (int *data,int low,int high) {
    int key,i,j,pivot;
    if( low < high) {
        pivot = choosePivot(low, high);
        swap(&data[low],&data[pivot]);
        key = data[low];
        i = low + 1;
        j = high;
        while(i <= j) {
            while((i <= high) && (data[i] <= key)) { i++; }
            while((j >= low) && (data[j] > key)) { j--; }
            if( i < j) { swap(&data[i],&data[j]); }
        }
        swap(&data[low],&data[j]);
        quickSort(data,low,j-1);
        quickSort(data,j+1,high);
    }
}
void reverseQuickSort (int *data,int low,int high) {
    int key,i,j,pivot;
    if( low < high) {
        pivot = choosePivot(low, high);
        swap(&data[low],&data[pivot]); 
        key = data[low];
        i = low + 1;
        j = high;
        while(i <= j) {
            while((i <= high) && (data[i] >= key)) { i++; }
            while((j >= low) && (data[j] < key)) { j--; }
            if( i < j) { swap(&data[i],&data[j]);}
        }
        swap(&data[low],&data[j]);
        reverseQuickSort(data,low,j-1);
        reverseQuickSort(data,j+1,high);
    }
}
void heapSort () {

}
void reverseHeapSort (){

}
void mergeSort () {

}
void reverseMergeSort () {

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