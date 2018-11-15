/******************************************************
* * This file contains the functions for building a * *
* * * * * * * * * Binary Maximal Heap * * * * * * * * * 
*******************************************************/
int PARENT(int i) {
	return (i-1)/2;
}
int LEFTchild(int i){
	return 2*i + 1;
}
int RIGHTchild(int i){
	return 2*i + 2;
}
void swap(int *item_1, int *item_2, unsigned long int *times){
    int temp = *item_1; 
    *item_1 = *item_2; 
    *item_2 = temp;
    *times = *times +1;
}
void permute(int *item_1, int *item_2){ // no track of swaps
    int temp = *item_1; 
    *item_1 = *item_2; 
    *item_2 = temp;
}
void PercolateUp(dataArray *arr, int index){//O(log n)
	int parent = PARENT(index);
	while ( ((arr->priority == max) && (parent >= 0) && (arr->data[parent] < arr->data[index]))
         || ((arr->priority == min) && (parent >= 0) && (arr->data[parent] > arr->data[index])) ){
		swap(&arr->data[index],&arr->data[parent],&arr->swaps);
		index = parent;
		parent = PARENT(index);
	}
}
void PercolateDownV1(dataArray *arr, unsigned long int end, unsigned long int index){
	int left = LEFTchild(index), 
		right = RIGHTchild(index), 
		current = index;
	if ( ((arr->priority == max) && (left < end) && (arr->data[index] < arr->data[left]))
      || ((arr->priority == min) && (left < end) && (arr->data[index] > arr->data[left])) ) {
		current = left;
	}
	if ( ((arr->priority == max) && (right < end) && (arr->data[current] < arr->data[right]))
      || ((arr->priority == min) && (right < end) && (arr->data[current] > arr->data[right])) ){
		current = right;
	}
	if (current != index){
		swap(&arr->data[index], &arr->data[current],&arr->swaps);
		PercolateDownV1(arr, end, current);
	}
}
void PercolateDown (dataArray *arr, unsigned long int end, unsigned long int index) {//O(log n)
    int current = index, left, right;
    while (1) {
        left=LEFTchild(index);
        right=RIGHTchild(index);
        if ( ((arr->priority == max) && (left < end) && (arr->data[left] > arr->data[current]))
          || ((arr->priority == min) && (left < end) && (arr->data[left] < arr->data[current]))) {
            current = left;
        }
        if (((arr->priority == max) && (right < end) && (arr->data[right] > arr->data[current]))
        ||  ((arr->priority == min) && (right < end) && (arr->data[right] < arr->data[current])) ) {
            current = right;
        }
        if (current == index) { break; }
        swap(&arr->data[index],&arr->data[current],&arr->swaps);
        index = current;
    }
}
void BuildHeap(dataArray *arr){// O(n)
    for (int i = arr->size / 2; i >= 0; i--){
        PercolateDown(arr, arr->size, i);
    }
}
int REMOVE(dataArray *arr, unsigned long int index){//O(log(n))
	int removed = arr->data[index];// printf("rm %d ",arr->data[index]);
	arr->data[index] = arr->data[arr->size - 1];
	arr->size = arr->size - 1;
	PercolateDown(arr, arr->size, index);
	if (index!=0) {PercolateUp(arr, index);}
	return removed;
}
int REMOVEbis(dataArray *arr, unsigned long int index){//printf("\nRemoving root element %d from heap\n",data[0]);
	int removed = arr->data[index];// printf("rm %d ",arr->data[index]);
	swap(&arr->data[index],&arr->data[arr->size - 1],&arr->swaps);
	arr->size = arr->size - 1;
	PercolateDown(arr, arr->size, index);
	if (index!=0) {PercolateUp(arr, index);}
	return removed;
}
void ADD(dataArray *arr, int element){//O(log(n))
	if ( arr->size < arr->length){
		arr->data[arr->size] = element;
		arr->size = arr->size + 1;
		PercolateUp(arr, arr->size -1);
	}
}
void k_REMOVE(dataArray *arr, int times){
	extern rezStruct result;
	for (int i = 0; i < times; i++){
			result.data[i] = REMOVE(arr,0);
		}
}
void k_ADD(dataArray *arr, dataArray elements, unsigned long int nr_items){
	for (int i = 0; i< nr_items; i++){
		ADD(arr,elements.data[i]);
	}
}
//delete min O(n)
//decrease key O(log n)
/*Algorithm	Average	 Worst case
Space		O(n)	 O(n)
Search		O(n)	 O(n)
Insert		O(1)	 O(log n)
Delete		O(log n) O(log n)
Peek		O(1)	 O(1)*/