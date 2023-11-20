#include <stdio.h>

#define MAX_SIZE 10

struct Queue {
    int front, rear;
    int array[MAX_SIZE];
};

int isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

int isEmpty(struct Queue* queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear++;
    queue->array[queue->rear] = item;
    printf("%d enqueued to the queue.\n", item);
}

int main() {
    struct Queue myQueue = { -1, -1 };

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    return 0;
}