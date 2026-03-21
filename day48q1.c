#include <stdio.h>
#include <stdlib.h>

// Tree Node Structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    // Base case
    if (root == NULL)
        return 0;

    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recursive call
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}