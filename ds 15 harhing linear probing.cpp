#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  // Size of the hash table
#define EMPTY -1 // Sentinel value for empty slot

int hashTable[SIZE];

// Function to initialize hash table
void initHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Function to display the hash table
void displayHashTable() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != EMPTY)
            printf("Index %d --> %d\n", i, hashTable[i]);
        else
            printf("Index %d --> EMPTY\n", i);
    }
}

// Function to insert a key using linear probing
void insert(int key) {
    int index = key % SIZE; // Hash function
    int startIndex = index; // Remember starting index for loop detection

    while (hashTable[index] != EMPTY) {
        index = (index + 1) % SIZE; // Move to next index
        if (index == startIndex) {
            printf("Hash Table is FULL! Cannot insert %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
    printf("%d inserted at index %d\n", key, index);
}

// Function to search for a key
void search(int key) {
    int index = key % SIZE;
    int startIndex = index;

    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            printf("%d found at index %d\n", key, index);
            return;
        }
        index = (index + 1) % SIZE;
        if (index == startIndex) break; // Full cycle
    }
    printf("%d not found in the hash table.\n", key);
}

// Main function
int main() {
    int choice, key;

    initHashTable();

    while (1) {
        printf("\n--- Hash Table Menu (Linear Probing) ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                displayHashTable();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

