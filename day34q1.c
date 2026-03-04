#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;   // Initially stack is empty

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
    printf("%d pushed into stack\n", value);
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int popped = stack[top];
    top--;
    return popped;
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    return 0;
}
