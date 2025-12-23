#include <stdio.h>
#include <stdlib.h>

int insert(int arr[], int n, int pos, int value) {
    int i;
    for (i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    return n + 1;
}

int delete(int arr[], int n, int pos) {
    int i;
    for (i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[50] = {10, 20, 30, 40};
    int n = 4;

    printArray(arr, n);

    n = insert(arr, n, 2, 25);
    printArray(arr, n);

    n = delete(arr, n, 1);
    printArray(arr, n);

    return 0;
}
