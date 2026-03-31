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

// Search index in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree function
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end) return NULL;

    // Pick root from postorder
    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = createNode(rootVal);

    // If only one node
    if (start == end) return root;

    int inIndex = search(inorder, start, end, rootVal);

    // IMPORTANT: build right first
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Inorder traversal (to check)
void inorderPrint(struct Node* root) {
    if (root != NULL) {
        inorderPrint(root->left);
        printf("%d ", root->data);
        inorderPrint(root->right);
    }
}

// Main function
int main() {
    int inorder[]   = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = 5;

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Inorder of constructed tree: ");
    inorderPrint(root);

    return 0;
}