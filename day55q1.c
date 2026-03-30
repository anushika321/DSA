#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure
struct Queue {
    struct Node* data;
    struct Queue* next;
};

// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Enqueue
void enqueue(struct Queue** front, struct Queue** rear, struct Node* node) {
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->data = node;
    temp->next = NULL;

    if (*rear == NULL) {
        *front = *rear = temp;
        return;
    }

    (*rear)->next = temp;
    *rear = temp;
}

// Dequeue
struct Node* dequeue(struct Queue** front, struct Queue** rear) {
    if (*front == NULL) return NULL;

    struct Queue* temp = *front;
    struct Node* node = temp->data;

    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;

    free(temp);
    return node;
}

// Check empty
int isEmpty(struct Queue* front) {
    return front == NULL;
}

// Right View function
void rightView(struct Node* root) {
    if (root == NULL) return;

    struct Queue* front = NULL;
    struct Queue* rear = NULL;

    enqueue(&front, &rear, root);

    while (!isEmpty(front)) {
        int size = 0;

        // Count current level size
        struct Queue* temp = front;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        for (int i = 0; i < size; i++) {
            struct Node* node = dequeue(&front, &rear);

            // Last node of level
            if (i == size - 1) {
                printf("%d ", node->data);
            }

            if (node->left)
                enqueue(&front, &rear, node->left);
            if (node->right)
                enqueue(&front, &rear, node->right);
        }
    }
}

// Main function
int main() {
    /*
            1
           / \
          2   3
           \    \
            5    4
    */

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(5);
    root->right->right = createNode(4);

    printf("Right View of Binary Tree: ");
    rightView(root);

    return 0;
}