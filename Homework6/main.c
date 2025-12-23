#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode;
    return newNode;
}

struct Node* insertAfter(struct Node* head, int key, int value) {
    struct Node* temp = head;

    if (head == NULL)
        return createNode(value);

    do {
        if (temp->data == key) {
            struct Node* newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    } while (temp != head);

    return head;
}

struct Node* deleteNode(struct Node* head, int key) {
    struct Node* curr = head;
    struct Node* prev = NULL;

    if (head == NULL)
        return NULL;

    do {
        if (curr->data == key) {
            if (prev != NULL) {
                prev->next = curr->next;
            } else {
                struct Node* last = head;
                while (last->next != head)
                    last = last->next;
                head = curr->next;
                last->next = head;
            }

            if (curr == curr->next) {
                free(curr);
                return NULL;
            }

            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    return head;
}

void traverse(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL)
        return;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    struct Node* head = createNode(10);
    head = insertAfter(head, 10, 20);
    head = insertAfter(head, 20, 30);

    traverse(head);

    head = insertAfter(head, 20, 25);
    traverse(head);

    head = deleteNode(head, 10);
    traverse(head);

    return 0;
}
