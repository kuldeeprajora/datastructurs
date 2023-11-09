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

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Oops! Can't add %d, the stack is full.\n", value);
    } else {
        stack->top++;
        stack->items[stack->top] = value;
        printf("Added %d to the stack. Nice!\n", value);
    }
}

int pop(struct Stack *stack) {
    int poppedItem;
    if (isEmpty(stack)) {
        printf("Uh-oh! Can't remove, the stack is empty.\n");
        return -1;
    } else {
        poppedItem = stack->items[stack->top];
        stack->top--;
        printf("Removed %d from the stack. Phew!\n", poppedItem);
        return poppedItem;
    }
}

int main() {
    struct Stack myStack;
    initialize(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Just checking... Popped element: %d\n", pop(&myStack));
    printf("And again... Popped element: %d\n", pop(&myStack));
    printf("One more time... Popped element: %d\n", pop(&myStack));
    printf("Any more? Popped element: %d\n", pop(&myStack));

    return 0;
}
