#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAfter(struct Node* head, int key, int value) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp != NULL) {
        struct Node* newNode = createNode(value);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }
}

struct Node* deleteNode(struct Node* head, int key) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL)
        return head;

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}

void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    traverse(head);

    insertAfter(head, 20, 25);
    traverse(head);

    head = deleteNode(head, 10);
    traverse(head);

    return 0;
}
