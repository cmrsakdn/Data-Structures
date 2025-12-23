#include <stdio.h>
#include <stdlib.h>

int tree[100];
int n = 0;

void insert(int value) {
    tree[n] = value;
    n++;
}

void traverse(int index) {
    if (index >= n)
        return;

    traverse(2 * index + 1);
    printf("%d ", tree[index]);
    traverse(2 * index + 2);
}

int main() {
    int i, value, count;

    printf("Enter number of nodes: ");
    scanf("%d", &count);

    for (i = 0; i < count; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        insert(value);
    }

    printf("Inorder traversal: ");
    traverse(0);
    printf("\n");

    return 0;
}
