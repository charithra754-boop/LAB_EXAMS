#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *prev, *next; } Node;
Node *head = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data; newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertFront(int data) {
    Node* newNode = createNode(data);
    if (head) { newNode->next = head; head->prev = newNode; }
    head = newNode;
    printf("Inserted %d at Front. Bienvenue!\n", data);
}

void insertEnd(int data) {
    Node* newNode = createNode(data);
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode; newNode->prev = temp;
    printf("Inserted %d at End. Willkommen!\n", data);
}

void insertPos(int data, int pos) {
    if (pos == 1) { insertFront(data); return; }
    Node* newNode = createNode(data);
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++) temp = temp->next;
    if (!temp) { printf("Invalid Pos! Ne?\n"); return; }
    newNode->next = temp->next; newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
    printf("Inserted %d at Pos %d. Chalo!\n", data, pos);
}

void deleteFront() {
    if (!head) { printf("List Empty!\n"); return; }
    Node* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    printf("Deleted %d from Front. Hasta la vista!\n", temp->data);
    free(temp);
}

void deleteEnd() {
    if (!head) { printf("List Empty!\n"); return; }
    if (!head->next) { deleteFront(); return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->prev->next = NULL;
    printf("Deleted %d from End. Arrivederci!\n", temp->data);
    free(temp);
}

void deletePos(int pos) {
    if (!head) { printf("List Empty!\n"); return; }
    if (pos == 1) { deleteFront(); return; }
    Node* temp = head;
    for (int i = 1; i < pos && temp; i++) temp = temp->next;
    if (!temp) { printf("Invalid Pos!\n"); return; }
    temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    printf("Deleted %d from Pos %d. Annyeong!\n", temp->data, pos);
    free(temp);
}

void display() {
    Node* temp = head;
    printf("List: ");
    while (temp) { printf("%d <-> ", temp->data); temp = temp->next; }
    printf("NULL\n");
}

int main() {
    int ch, x, pos;
    printf("--- Doubly Linked List (Exam Q3) ---\n");
    while (1) {
        printf("\n1.InsFront 2.InsEnd 3.InsPos 4.DelFront 5.DelEnd 6.DelPos 7.Show 8.Exit: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Val: "); scanf("%d", &x); insertFront(x); break;
            case 2: printf("Val: "); scanf("%d", &x); insertEnd(x); break;
            case 3: printf("Val: "); scanf("%d", &x); printf("Pos: "); scanf("%d", &pos); insertPos(x, pos); break;
            case 4: deleteFront(); break;
            case 5: deleteEnd(); break;
            case 6: printf("Pos: "); scanf("%d", &pos); deletePos(pos); break;
            case 7: display(); break;
            case 8: exit(0);
        }
    }
}
