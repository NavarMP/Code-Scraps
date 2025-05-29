//15. Traverse a binary search tree in pre-order

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new binary tree node
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to traverse a binary search tree in pre-order
void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data); // visit the current node
    preOrderTraversal(root->left); // traverse the left subtree
    preOrderTraversal(root->right); // traverse the right subtree
}

// Function to insert a node into the binary search tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int main() {
    printf("Enter the number of nodes in the binary search tree: ");
    int n;
    scanf("%d", &n);

    Node* root = NULL;

    printf("Enter the nodes of the binary search tree (in any order):\n");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    return 0;
}