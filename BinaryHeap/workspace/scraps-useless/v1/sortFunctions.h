/*******************************************************
* * * * This file contains the functions sorting * * * *
* * * * * * * Min to Max and Reversed sort * * * * * * * 
********************************************************/
void swap(int *item_1, int *item_2){ // same as Permut()
    int temp = *item_1; 
    *item_1 = *item_2; 
    *item_2 = temp; 
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
void quickSort (){
}
void reverseQuickSort (){
}
void reverseHeapSort (){
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