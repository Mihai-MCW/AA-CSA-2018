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
void Permut(int *item_1, int *item_2){ // same as swap()
		int temp = *item_1; 
		*item_1 = *item_2; 
		*item_2 = temp; 
}
void PercolateUp(dataArray *arr, int current){
	int parent = PARENT(current);
	while (parent >= 0 && arr->data[parent] < arr->data[current]){
		Permut(&arr->data[current],&arr->data[parent]);
		current = parent;
		parent = PARENT(current);
	}
}
void PercolateDown(dataArray *arr, int current){
	int left = LEFTchild(current), 
		right = RIGHTchild(current), 
		curr_largest = current;
	if ( (left < arr->size) && ( arr->data[current] < arr->data[left] ) ){
		curr_largest = left;
	}
	if ( (right < arr->size) && ( arr->data[curr_largest] < arr->data[right] ) ){
		curr_largest = right;
	}
	if (curr_largest != current){
		Permut(&arr->data[current], &arr->data[curr_largest]);
		PercolateDown(arr, curr_largest);
	}
}
void BuildHeap(dataArray *arr){//printf("\nBuilding maximal heap\n");
    for (int i = arr->size / 2; i >= 0; i--){
        PercolateDown(arr, i);
    }
}
int REMOVE(dataArray *arr){//printf("\nRemoving root element %d from heap\n",data[0]);
	int removed = arr->data[0];
	arr->data[0] = arr->data[arr->size-1];
	arr->size = arr->size - 1;
	PercolateDown(arr,0);
	return removed;
}
void ADD(dataArray *arr, int element){//printf("\nAdding element %d to the heap\n",element);
	if ( arr->size < arr->length){
		arr->data[arr->size] = element;
		arr->size = arr->size + 1;
		PercolateUp(arr,(arr->size-1));
	}
}
int k_REMOVE(dataArray *arr, int times){
	for (int i = 0; i < times; i++){
			REMOVE(arr);
		}
}
void k_ADD(dataArray *arr, dataArray *list, unsigned long nr_items){
	for (int i = 0; i< nr_items; i++){
		ADD(arr,list->data[i]);
	}
}