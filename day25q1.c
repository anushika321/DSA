#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to count occurrences
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}

// Helper function to insert at end
struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Driver code
int main() {
    struct Node* head = NULL;

    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 1);
    head = insert(head, 3);
    head = insert(head, 1);

    int key = 1;
    printf("Occurrences of %d: %d\n", key, countOccurrences(head, key));

    return 0;
}
