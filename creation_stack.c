#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d.\n", item);
    } else {
        stack->items[++stack->top] = item;
    }
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    } else {
        int item = stack->items[stack->top--];
        return item;
    }
}

int main() {
    struct Stack myStack;
    initialize(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    pop(&myStack);
    pop(&myStack);
    pop(&myStack);
    pop(&myStack);

    return 0;
}
