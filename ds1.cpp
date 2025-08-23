#include <stdio.h>
#define SIZE 100   // Maximum size of stack

int stack[SIZE];
int top = -1;

// Function to check if stack is full
int isFull() {
    return top == SIZE - 1;
}

// Function to check if stack is empty
int isEmpty() {
    return top == -1;
}

// PUSH operation
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// POP operation
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop\n");
    } else {
        printf("%d popped from stack\n", stack[top--]);
    }
}

// PEEK operation
void peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

// Display stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main program
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

