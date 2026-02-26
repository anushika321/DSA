#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Insert at Beginning
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    return newNode;
}

// Insert at End
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Insert at Position (1-based index)
struct Node* insertAtPosition(struct Node* head, int value, int pos) {
    if (pos == 1)
        return insertAtBeginning(head, value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

// Delete from Beginning
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
    return head;
}

// Delete from End
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
    return head;
}

// Delete from Position (1-based index)
struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (head == NULL)
        return NULL;

    if (pos == 1)
        return deleteAtBeginning(head);

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        return head;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return head;
}

// Forward Traversal
void traverseForward(struct Node* head) {
    struct Node* temp = head;
    while (temp !=
