#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Count nodes
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check Complete Binary Tree
int isCBT(struct Node* root, int index, int totalNodes) {
    if (root == NULL) return 1;

    if (index >= totalNodes)
        return 0;

    return isCBT(root->left, 2 * index + 1, totalNodes) &&
           isCBT(root->right, 2 * index + 2, totalNodes);
}

// Check Min Heap property
int isMinHeap(struct Node* root) {
    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Only left child
    if (root->right == NULL) {
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);
    }

    // Both children
    return (root->data <= root->left->data &&
            root->data <= root->right->data) &&
           isMinHeap(root->left) &&
           isMinHeap(root->right);
}

// Final check
int isHeap(struct Node* root) {
    int totalNodes = countNodes(root);

    if (isCBT(root, 0, totalNodes) && isMinHeap(root))
        return 1;

    return 0;
}

// Main function
int main() {
    /*
            10
           /  \
         20    30
        /  \
      40   50
    */

    struct Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    if (isHeap(root))
        printf("Valid Min Heap\n");
    else
        printf("Not a Min Heap\n");

    return 0;
}