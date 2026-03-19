struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
#define MAX 100

struct Node* queue[MAX];
int front = 0, rear = -1;

void enqueue(struct Node* node) {
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[front++];
}
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (front <= rear) {
        struct Node* curr = dequeue();
        printf("%d ", curr->data);

        if (curr->left)
            enqueue(curr->left);

        if (curr->right)
            enqueue(curr->right);
    }
}
