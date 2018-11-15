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
void permute(int *item_1, int *item_2){
    int temp = *item_1; 
    *item_1 = *item_2; 
    *item_2 = temp;
}
void PercolateUp(dataArray *arr, int current){
	int parent = PARENT(current);
	while ( ((arr->priority == max) && (parent >= 0) && (arr->data[parent] < arr->data[current]))
         || ((arr->priority == min) && (parent >= 0) && (arr->data[parent] > arr->data[current])) ){
		swap(&arr->data[current],&arr->data[parent],&arr->swaps);
		current = parent;
		parent = PARENT(current);
	}
}
void PercolateDown (dataArray *arr, unsigned long int end, unsigned long int initial) {
    int current = initial, left, right;
    while (1) {
        left=LEFTchild(initial);
        right=RIGHTchild(initial);
        if ( ((arr->priority == max) && (left < end) && (arr->data[left] > arr->data[current]))
          || ((arr->priority == min) && (left < end) && (arr->data[left] < arr->data[current]))) {
            current = left;
        }
        if (((arr->priority == max) && (right < end) && (arr->data[right] > arr->data[current]))
        ||  ((arr->priority == min) && (right < end) && (arr->data[right] < arr->data[current])) ) {
            current = right;
        }
        if (current == initial) { break; }
        swap(&arr->data[initial],&arr->data[current],&arr->swaps);
        initial = current;
    }
}
void PercolateDownV1(dataArray *arr, unsigned long int end, unsigned long int initial){
	int left = LEFTchild(initial), 
		right = RIGHTchild(initial), 
		current = initial;
	if ( ((arr->priority == max) && (left < end) && (arr->data[initial] < arr->data[left]))
      || ((arr->priority == min) && (left < end) && (arr->data[initial] > arr->data[left])) ) {
		current = left;
	}
	if ( ((arr->priority == max) && (right < end) && (arr->data[current] < arr->data[right]))
      || ((arr->priority == min) && (right < end) && (arr->data[current] > arr->data[right])) ){
		current = right;
	}
	if (current != initial){
		swap(&arr->data[initial], &arr->data[current],&arr->swaps);
		PercolateDownV1(arr, end, current);
	}
}
void BuildHeap(dataArray *arr){//printf("\nBuilding maximal heap\n");
    for (int i = arr->size / 2; i >= 0; i--){
        PercolateDown(arr, arr->size, i);
    }
}
void REMOVE(dataArray *arr, unsigned long int index){//printf("\nRemoving root element %d from heap\n",data[0]);
	printf("rm %d",arr->data[0]);
	arr->data[index] = arr->data[arr->size - 1];
	arr->size = arr->size - 1;
	PercolateDown(arr, arr->size, index);
	if (index!=0) {PercolateUp(arr, index);}
	//return removed;
}

void ADD(dataArray *arr, int element){//printf("\nAdding element %d to the heap\n",element);
	if ( arr->size < arr->length){
		arr->data[arr->size] = element;
		arr->size = arr->size + 1;
		PercolateUp(arr, arr->size -1);
	}
}
void k_REMOVE(dataArray *arr, int times){
	for (int i = 0; i < times; i++){
			REMOVE(arr,0);
		}
}
void k_ADD(dataArray *arr, dataArray elements, unsigned long int nr_items){
	for (int i = 0; i< nr_items; i++){
		ADD(arr,elements.data[i]);
	}
}