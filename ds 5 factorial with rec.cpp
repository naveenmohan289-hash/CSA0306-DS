#include <stdio.h>

// Recursive function to find factorial
long long factorial(int n) {
    if (n == 0 || n == 1)  // Base case
        return 1;
    else
        return n * factorial(n - 1);  // Recursive call
}

int main() {
    int num;

    // Input number
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Check for negative numbers
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d = %lld\n", num, factorial(num));
    }

    return 0;
}

