#include <stdio.h>

int main() {
    int n, i;

    // Input: number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Handle small cases
    if (n <= 0) {
        printf("Please enter a positive number of terms.\n");
        return 0;
    }

    // Create an array to store Fibonacci series
    int fib[n];

    // Initialize first two terms
    fib[0] = 0;
    if (n > 1)
        fib[1] = 1;

    // Generate Fibonacci series iteratively
    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Print the Fibonacci series
    printf("Fibonacci Series: ");
    for (i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    return 0;
}

