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
    int *data;
    unsigned long int size;
} rezStruct;