#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int bosMu() {
    return top == -1;
}

int oncelik(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char infix[50];
    char postfix[50];
    int k = 0;

    printf("Infix ifadeyi gir: ");
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (c >= '0' && c <= '9') {
            postfix[k++] = c;
            postfix[k++] = ' ';
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!bosMu() && stack[top] != '(') {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            if (!bosMu()) pop();
        }
        else {
            while (!bosMu() && oncelik(stack[top]) >= oncelik(c)) {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            push(c);
        }
    }

    while (!bosMu()) {
        postfix[k++] = pop();
        postfix[k++] = ' ';
    }

    postfix[k] = '\0';

    printf("Postfix: %s\n", postfix);

    return 0;
}
