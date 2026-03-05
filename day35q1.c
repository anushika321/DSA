#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char x) {
    stack[++top] = x;
}

// Pop
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

// Precedence function
int precedence(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

int main() {
    char exp[100], result[100];
    int i = 0, k = 0;
    
    printf("Enter Infix Expression: ");
    scanf("%s", exp);

    while (exp[i] != '\0') {

        // Operand
        if (isalnum(exp[i])) {
            result[k++] = exp[i];
        }

        // Opening bracket
        else if (exp[i] == '(') {
            push(exp[i]);
        }

        // Closing bracket
        else if (exp[i] == ')') {
            while (stack[top] != '(') {
                result[k++] = pop();
            }
            pop(); // remove '('
        }

        // Operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i])) {
                result[k++] = pop();
            }
            push(exp[i]);
        }

        i++;
    }

    // Pop remaining operators
    while (top != -1) {
        result[k++] = pop();
    }

    result[k] = '\0';

    printf("Postfix Expression: %s\n", result);

    return 0;
}
