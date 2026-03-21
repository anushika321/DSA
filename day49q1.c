#include <stdio.h>
#include <stdlib.h>

// Define Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    // If tree is empty
    if (root == NULL) {
        return createNode(val);
    }

    // Go to left subtree
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    // Go to right subtree
    else {
        root->right = insert(root->right, val);
    }

    return root;
}