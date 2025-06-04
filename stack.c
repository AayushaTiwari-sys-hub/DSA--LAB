#include <stdio.h>
#define MAX 100

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Initialize stack
void init(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push operation
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++s->top] = value;
    printf("Pushed %d\n", value);
}

// Pop operation
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Peek operation
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

// Display stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate
int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    display(&s);

    printf("Top element: %d\n", peek(&s));

    printf("Popped element: %d\n", pop(&s));

    display(&s);

    return 0;
}
