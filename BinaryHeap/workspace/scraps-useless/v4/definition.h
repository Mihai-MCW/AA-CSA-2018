typedef enum {
    min,
    max
} priority_t;
typedef struct {
    int *data;
    unsigned long int size;
    unsigned long int length;
    unsigned long int swaps;
    priority_t priority;
} dataArray;
typedef struct {
    dataArray Heap;
} binaryHeap;
typedef struct {
    dataArray Array;
} intArray;
/*
dataArray *initArray(int m){
    dataArray *da = (dataArray *)malloc(sizeof(dataArray)+m*sizeof(int));
    da->size = 0;
    da->length = m;
    return da;
}
dataArray *resizeDataArray(dataArray *da, int m){
    if (m <= da->size){
         return da; 
    }
    dataArray *da = (dataArray *)realloc(sizeof(dataArray)+m*sizeof(int));
    da->length = m;
    return da;
}*/