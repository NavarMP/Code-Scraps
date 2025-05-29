//18. Search an element in a binary search tree

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

// Function to search an element in a binary search tree
Node* searchBST(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (root->data < key) {
        return searchBST(root->right, key);
    } else {
        return searchBST(root->left, key);
    }
}

int main() {
    prinft ("Search an element in a binary search tree\n");

    // Create a sample binary search tree
    Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(8);

    int key = 4; // element to search
    Node* result = searchBST(root, key);

    if (result != NULL) {
        printf("Element %d found in the binary search tree.\n", key);
    } else {
        printf("Element %d not found in the binary search tree.\n", key);
    }

    return 0;
}