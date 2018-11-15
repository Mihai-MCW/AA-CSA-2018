typedef enum {
    min,
    max
} priority_t;
typedef struct {
    int *h_data;
    unsigned long int size;
    unsigned long int length;
    priority_t priority;
} dataArray;
typedef struct {
    dataArray Heap;
} binaryHeap;
typedef struct {
    dataArray Array;
} intArray;
