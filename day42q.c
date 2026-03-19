#include <stdio.h>
#define MAX 100

// Queue
int queue[MAX];
int front = -1, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Queue Functions
void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = val;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

// Stack Functions
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Reverse Function
void reverseQueue() {
    // Step 1: Queue → Stack
    while (front <= rear) {
        push(dequeue());
    }

    // Step 2: Stack → Queue
    while (top != -1) {
        enqueue(pop());
    }
}

// Display
void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    printf("Original Queue: ");
    display();

    reverseQueue();

    printf("Reversed Queue: ");
    display();

    return 0;
}