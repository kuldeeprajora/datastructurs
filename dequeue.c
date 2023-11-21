#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void dequeue() {
    if (front == -1) {
        printf("Queue is empty. Dequeue operation cannot be performed.\n");
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1; 
        }
    }
}

int main() {

    queue[++rear] = 10;
    queue[++rear] = 20;
    queue[++rear] = 30;

    // 
    dequeue();
    dequeue();
    dequeue();

    return 0;
}