#include <stdio.h>

int main() {
    int n, i;
    long long factorial = 1;  // Use long long for large results

    // Input from user
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Check for negative numbers
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // Loop to calculate factorial
        for (i = 1; i <= n; i++) {
            factorial *= i;
        }

        // Display result
        printf("Factorial of %d = %lld\n", n, factorial);
    }

    return 0;
}

