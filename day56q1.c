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

// Check mirror
int isMirror(struct Node* left, struct Node* right) {
    // Both NULL → symmetric
    if (left == NULL && right == NULL)
        return 1;

    // One NULL → not symmetric
    if (left == NULL || right == NULL)
        return 0;

    // Check data and recursive mirror
    return (left->data == right->data) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Main symmetric function
int isSymmetric(struct Node* root) {
    if (root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}

// Main function
int main() {
    /*
        Symmetric Tree Example:

                1
               / \
              2   2
             / \ / \
            3  4 4  3
    */

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(4);
    root->right->right = createNode(3);

    if (isSymmetric(root))
        printf("Tree is Symmetric\n");
    else
        printf("Tree is NOT Symmetric\n");

    return 0;
}