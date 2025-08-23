#include <stdio.h>
#define SIZE 100

int arr[SIZE];
int n = 0; // Current size of the array

// Function to display the array
void display() {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to insert an element at a given position
void insert() {
    int pos, value;
    if (n == SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &value);
    printf("Enter position (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to make space
    for (int i = n - 1; i >= pos; i--)
        arr[i + 1] = arr[i];

    arr[pos] = value;
    n++;
    printf("%d inserted at position %d.\n", value, pos);
}

// Function to delete an element from a given position
void delete() {
    int pos;
    if (n == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    printf("Enter position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }

    int deleted = arr[pos];

    // Shift elements to fill the gap
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;
    printf("%d deleted from position %d.\n", deleted, pos);
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

