#include <stdio.h>

int main() {
    int n, i, key, found = 0;

    // Input: number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Array to store elements

    // Input: array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input: element to search
    printf("Enter the number to search: ");
    scanf("%d", &key);

    // Linear search logic
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("%d found at position %d (index %d)\n", key, i + 1, i);
            found = 1;
            break;  // Stop after finding the element
        }
    }

    // If not found
    if (!found) {
        printf("%d not found in the array.\n", key);
    }

    return 0;
}

