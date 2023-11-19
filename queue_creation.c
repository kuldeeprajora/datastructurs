#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

int isFull(struct Queue* q) {
    return (q->rear == MAX_SIZE - 1);
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
    }

    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    int item;

    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    item = q->items[q->front];
    q->front++;

    if (q->front > q->rear) {
        initializeQueue(q);
    }

    return item;
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    display(&myQueue);

    printf("Dequeued item: %d\n", dequeue(&myQueue));
    printf("Dequeued item: %d\n", dequeue(&myQueue));

    display(&myQueue);

    return 0;
}
