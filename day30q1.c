#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int length = 1;

    // Step 1: Find length
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Step 2: Make it circular
    temp->next = head;

    // Step 3: Reduce k
    k = k % length;
    int stepsToNewHead = length - k;

    // Step 4: Find new tail
    temp = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        temp = temp->next;
    }

    // Step 5: Break the circle
    head = temp->next;
    temp->next = NULL;

    return head;
}
