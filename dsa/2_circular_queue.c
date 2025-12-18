#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int q[MAX], f = -1, r = -1;

void enqueue(int val) {
    if ((r + 1) % MAX == f) printf("Queue Full! Mamma Mia!\n");
    else {
        if (f == -1) f = 0;
        r = (r + 1) % MAX;
        q[r] = val;
        printf("Inserted %d. Allons-y!\n", val);
    }
}

void dequeue() {
    if (f == -1) printf("Queue Empty! Aiyyo!\n");
    else {
        printf("Deleted %d. Tschüss!\n", q[f]);
        if (f == r) f = r = -1;
        else f = (f + 1) % MAX;
    }
}

void display() {
    if (f == -1) { printf("Queue Empty.\n"); return; }
    printf("Queue: ");
    for (int i = f; i != r; i = (i + 1) % MAX) printf("%d ", q[i]);
    printf("%d\n", q[r]);
}

int main() {
    int ch, x;
    printf("--- Circular Queue (Exam Q2) ---\n");
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Val: "); scanf("%d", &x); enqueue(x); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
        }
    }
}