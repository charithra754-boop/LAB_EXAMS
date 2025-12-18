#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data; newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (!root) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void inorder(Node* root) {
    if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}

void preorder(Node* root) {
    if (root) { printf("%d ", root->data); preorder(root->left); preorder(root->right); }
}

void postorder(Node* root) {
    if (root) { postorder(root->left); postorder(root->right); printf("%d ", root->data); }
}

int main() {
    Node* root = NULL; int ch, x;
    printf("--- Tree Traversal (Exam Q5) ---
");
    while (1) {
        printf("\n1.Insert 2.Inorder 3.Preorder 4.Postorder 5.Exit: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Val: "); scanf("%d", &x); root = insert(root, x); printf("Mashallah!\n"); break;
            case 2: printf("In (Andiamo): "); inorder(root); printf("\n"); break;
            case 3: printf("Pre (Vamos): "); preorder(root); printf("\n"); break;
            case 4: printf("Post (Yalla): "); postorder(root); printf("\n"); break;
            case 5: exit(0);
        }
    }
}
