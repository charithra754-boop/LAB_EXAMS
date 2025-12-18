#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key; newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (!root) return createNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

Node* minValueNode(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) { Node* temp = root->right; free(root); return temp; }
        if (!root->right) { Node* temp = root->left; free(root); return temp; }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int search(Node* root, int key) {
    if (!root) return 0;
    if (root->data == key) return 1;
    return key < root->data ? search(root->left, key) : search(root->right, key);
}

void inorder(Node* root) {
    if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}

int main() {
    Node* root = NULL; int ch, x;
    printf("--- BST (Exam Q4) ---\n");
    while (1) {
        printf("\n1.Insert 2.Delete 3.Search 4.Display 5.Exit: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Val: "); scanf("%d", &x); root = insert(root, x); printf("Subarashii!\n"); break;
            case 2: printf("Val: "); scanf("%d", &x); root = deleteNode(root, x); printf("Dasvidaniya!\n"); break;
            case 3: printf("Val: "); scanf("%d", &x); printf(search(root, x) ? "Eureka!\n" : "Nix da!\n"); break;
            case 4: printf("Tree: "); inorder(root); printf("\n"); break;
            case 5: exit(0);
        }
    }
}