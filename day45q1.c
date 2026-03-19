int height(struct Node* root) {
    if (root == NULL)
        return -1;   // if counting edges

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
if (root == NULL)
    return 0;