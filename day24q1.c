#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Traverse list
void traverseList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete first occurrence of a key
struct Node* deleteKey(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head itself has the key
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Key not found
    if (temp == NULL) return head;

    prev->next = temp->next;
    free(temp);
    return head;
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Original List: ");
    traverseList(head);

    head = deleteKey(head, 20);
    printf("After deleting 20: ");
    traverseList(head);

    head = deleteKey(head, 10);
    printf("After deleting 10 (head node): ");
    traverseList(head);

    head = deleteKey(head, 50);
    printf("After trying to delete 50 (not in list): ");
    traverseList(head);

    return 0;
}