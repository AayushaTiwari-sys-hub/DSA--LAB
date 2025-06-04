#include <stdio.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} LinearQueue;

void init(LinearQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(LinearQueue *q) {
    return q->front == -1;
}

int isFull(LinearQueue *q) {
    return q->rear == MAX - 1;
}

void enqueue(LinearQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q)) q->front = 0;
    q->arr[++q->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(LinearQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return value;
}

int peek(LinearQueue *q) {
    if (isEmpty(q)) return -1;
    return q->arr[q->front];
}

void display(LinearQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}
