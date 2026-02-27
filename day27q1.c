#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    if (headA == NULL || headB == NULL)
        return NULL;

    struct Node* ptr1 = headA;
    struct Node* ptr2 = headB;

    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == NULL) ? headB : ptr1->next;
        ptr2 = (ptr2 == NULL) ? headA : ptr2->next;
    }

    return ptr1;   // Either intersection node or NULL
}
