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

// Merge two sorted lists
struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1) ? l1 : l2;
    return dummy.next;
}

int main() {
    // List 1: 1 -> 3 -> 5
    struct Node* l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->next = createNode(5);

    // List 2: 2 -> 4 -> 6
    struct Node* l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(6);

    printf("List 1: ");
    traverseList(l1);
    printf("List 2: ");
    traverseList(l2);

    struct Node* merged = mergeSortedLists(l1, l2);
    printf("Merged List: ");
    traverseList(merged);

    return 0;
}