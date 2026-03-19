struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
int height(struct Node* root) {
    if (root == NULL)
        return -1;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + (left > right ? left : right);
}
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + (left > right ? left : right);
}
