#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// LCA function
struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If either n1 or n2 matches root
    if (root->data == n1 || root->data == n2)
        return root;

    // Search in left and right subtree
    struct Node* left = LCA(root->left, n1, n2);
    struct Node* right = LCA(root->right, n1, n2);

    // If both sides return non-null → LCA
    if (left != NULL && right != NULL)
        return root;

    // Else return non-null side
    return (left != NULL) ? left : right;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    /*
        Creating this tree manually:

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

    int n1, n2;
    printf("Enter two nodes to find LCA: ");
    scanf("%d %d", &n1, &n2);

    struct Node* lca = LCA(root, n1, n2);

    if (lca != NULL)
        printf("LCA of %d and %d is: %d\n", n1, n2, lca->data);
    else
        printf("LCA not found\n");

    return 0;
}