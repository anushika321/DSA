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

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find LCA in BST
struct Node* LCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        // Both values smaller → go left
        if (n1 < root->data && n2 < root->data)
            root = root->left;

        // Both values greater → go right
        else if (n1 > root->data && n2 > root->data)
            root = root->right;

        // Split point → LCA found
        else
            return root;
    }
    return NULL;
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
    struct Node* root = NULL;
    int n, value, n1, n2;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder Traversal: ");
    inorder(root);

    printf("\nEnter two nodes to find LCA: ");
    scanf("%d %d", &n1, &n2);

    struct Node* lca = LCA(root, n1, n2);

    if (lca != NULL)
        printf("LCA of %d and %d is: %d\n", n1, n2, lca->data);
    else
        printf("LCA not found\n");

    return 0;
}