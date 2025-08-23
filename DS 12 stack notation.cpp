#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    int items[MAX];
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

// Push element onto stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = value;
}

// Pop element from stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[s->top--];
}

// Peek top element
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

// Evaluate postfix expression
int evaluatePostfix(char *exp) {
    Stack s;
    init(&s);
    int i, op1, op2;

    for (i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            push(&s, ch - '0');  // Convert char to int
        } else {
            op2 = pop(&s);
            op1 = pop(&s);

            switch (ch) {
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
                default: printf("Invalid operator %c\n", ch); return -1;
            }
        }
    }

    return pop(&s);  // Result
}

// Main function
int main() {
    char postfixExp[MAX];

    printf("Enter a postfix expression (single-digit operands): ");
    scanf("%s", postfixExp);

    int result = evaluatePostfix(postfixExp);
    printf("Result of postfix expression %s = %d\n", postfixExp, result);

    return 0;
}

