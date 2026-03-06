#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int evaluatePostfix(char* exp) {
    int stack[100];
    int top = -1;

    for(int i = 0; exp[i] != '\0'; i++) {

        // If operand, push into stack
        if(isdigit(exp[i])) {
            stack[++top] = exp[i] - '0';
        }
        else {
            int val2 = stack[top--];
            int val1 = stack[top--];

            switch(exp[i]) {
                case '+': stack[++top] = val1 + val2; break;
                case '-': stack[++top] = val1 - val2; break;
                case '*': stack[++top] = val1 * val2; break;
                case '/': stack[++top] = val1 / val2; break;
            }
        }
    }

    return stack[top];
}

int main() {
    char exp[] = "231*+9-";
    printf("Result = %d", evaluatePostfix(exp));
    return 0;
}