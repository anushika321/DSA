#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue node for BFS
struct QNode {
    struct Node* node;
    int hd;
    struct QNode* next;
};

// Create tree node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Create queue node
struct QNode* createQNode(struct Node* node, int hd) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->node = node;
    temp->hd = hd;
    temp->next = NULL;
    return temp;
}

// Enqueue
void enqueue(struct QNode** front, struct QNode** rear, struct Node* node, int hd) {
    struct QNode* temp = createQNode(node, hd);
    if (*rear == NULL) {
        *front = *rear = temp;
        return;
    }
    (*rear)->next = temp;
    *rear = temp;
}

// Dequeue
struct QNode* dequeue(struct QNode** front, struct QNode** rear) {
    if (*front == NULL) return NULL;
    struct QNode* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    return temp;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct QNode* front = NULL;
    struct QNode* rear = NULL;

    // Simple array for storing values (HD range assumption)
    int map[200][100]; // map[hd+100][...]
    int count[200] = {0};

    enqueue(&front, &rear, root, 0);

    while (front != NULL) {
        struct QNode* temp = dequeue(&front, &rear);
        struct Node* curr = temp->node;
        int hd = temp->hd;

        int index = hd + 100; // shift to avoid negative index
        map[index][count[index]++] = curr->data;

        if (curr->left)
            enqueue(&front, &rear, curr->left, hd - 1);

        if (curr->right)
            enqueue(&front, &rear, curr->right, hd + 1);

        free(temp);
    }

    // Print vertical order
    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

// Main function
int main() {
    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}