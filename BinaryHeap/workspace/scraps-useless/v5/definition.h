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
    unsigned long int size;
    unsigned long int length;
    unsigned long int delete;
    unsigned long int add;
    unsigned long int sort;
    priority_t priority;
} init;