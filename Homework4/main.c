#include <stdio.h>
#include <stdlib.h>

int arr[100];
int n = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void goUp(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (arr[i] > arr[p]) {
            swap(&arr[i], &arr[p]);
            i = p;
        } else break;
    }
}

void goDown(int i) {
    while (2 * i + 1 < n) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int big = left;

        if (right < n && arr[right] > arr[left]) {
            big = right;
        }

        if (arr[big] > arr[i]) {
            swap(&arr[i], &arr[big]);
            i = big;
        } else break;
    }
}

void add(int val) {
    arr[n] = val;
    n++;
    goUp(n - 1);
}

int removeMax() {
    if (n == 0) return -1;
    int root = arr[0];
    arr[0] = arr[n - 1];
    n--;
    goDown(0);
    return root;
}

int main() {
    int cmd, val;

    while (1) {
        printf("\n1-Add 2-Remove 3-Show 0-Exit: ");
        scanf("%d", &cmd);

        if (cmd == 1) {
            printf("Value: ");
            scanf("%d", &val);
            add(val);
        } else if (cmd == 2) {
            int r = removeMax();
            if (r != -1) printf("Removed: %d\n", r);
        } else if (cmd == 3) {
            for (int i = 0; i < n; i++) printf("%d ", arr[i]);
            printf("\n");
        } else if (cmd == 0) break;
    }
    return 0;
}
