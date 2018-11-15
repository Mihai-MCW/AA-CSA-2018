#include <stdio.h>
#include "definition.h"
int maxim (int *a, int n, int i, int j, int k) {
    int m = i;
    if (j < n && a[j] > a[m]) {
        m = j;
    }
    if (k < n && a[k] > a[m]) {
        m = k;
    }
    return m;
}
 
void downheap (dataArray *arr, int n, int k) {
    while (1) {
        int j = maxim(arr->data, n, k, 2*k+1, 2*k+2);
        if (j == k) {
            break;
        }
        int t = arr->data[k];
        arr->data[k] = arr->data[j];
        arr->data[j] = t;
        k = j;
    }
}
 
void heapsort (dataArray *arr) {
    int i = (arr->size - 2) / 2;
    for (i; i >= 0; i--) {
        downheap(arr, arr->size, i);
    }
    for (i = 0; i < arr->size; i++) {
        int t = arr->data[arr->size - i - 1];
        arr->data[arr->size - i - 1] = arr->data[0];
        arr->data[0] = t;
        downheap(arr, arr->size - i - 1, 0);
    }
}
 
int main () {
    int x[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int n = sizeof x / sizeof x[0];
    dataArray arr[n]; arr->size = n; arr->length = n+5; arr->swaps = 0;
    for (int i = 0; i< n; i++){
        arr->data[i]=x[i];
    }
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", arr->data[i], i == n - 1 ? "\n" : " ");
    heapsort(arr);
    for (i = 0; i < n; i++)
        printf("%d%s", arr->data[i], i == n - 1 ? "\n" : " ");
    return 0;
}
 