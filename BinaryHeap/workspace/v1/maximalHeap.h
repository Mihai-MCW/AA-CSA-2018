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
void PercolateUp(int *data, int size, int current){
	int parent = PARENT(current);
	while (parent >= 0 && data[parent] < data[current]){
		Permut(&data[current],&data[parent]);//same as swap
		current = parent;
		parent = PARENT(current);
	}
}
void PercolateDown(int *data, int size, int current){
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
void BuildHeap(int *data, int size, int lenMax){//printf("\nBuilding maximal heap\n");
    for (int i = size / 2; i >= 0; i--){
        PercolateDown(data, size, i);
    }
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