#include <stdio.h>

int main() {
    int n, i, j, key;

    // Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insertion Sort Algorithm
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // Display sorted array
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

