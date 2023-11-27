#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initializeQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear++;
    queue->items[queue->rear] = value;
}

int dequeue(struct Queue* queue) {
    int value;

    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    value = queue->items[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        initializeQueue(queue);
    }

    return value;
}

int searchQueue(struct Queue* queue, int key) {
    for (int i = queue->front; i <= queue->rear; i++) {
        if (queue->items[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    int searchKey = 20;
    int index = searchQueue(&myQueue, searchKey);

    if (index != -1) {
        printf("Element %d found at index %d in the queue.\n", searchKey, index);
    } else {
        printf("Element %d not found in the queue.\n", searchKey);
    }

    return 0;
}