//17. Traverse a binary search tree in post-order

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

// Function to traverse a binary search tree in post-order
void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left); // traverse the left subtree
    postOrderTraversal(root->right); // traverse the right subtree
    printf("%d ", root->data); // visit the current node
}

int main() {
    printf ("Traverse a binary search tree in post-order\n");
    
    // Create a sample binary search tree
    Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(8);

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}