#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int arr[MAX], t1 = -1, t2 = MAX;

void push1(int data) {
    if (t1 < t2 - 1) { arr[++t1] = data; printf("Stack1: Pushed %d. Yatta!\n", data); }
    else printf("Stack Overflow! Ay caramba!\n");
}

void push2(int data) {
    if (t1 < t2 - 1) { arr[--t2] = data; printf("Stack2: Pushed %d. Très bien!\n", data); }
    else printf("Stack Overflow! Ay caramba!\n");
}

void pop1() {
    if (t1 >= 0) printf("Stack1: Popped %d. Adiós!\n", arr[t1--]);
    else printf("Stack1 Underflow! Omo!\n");
}

void pop2() {
    if (t2 < MAX) printf("Stack2: Popped %d. Sayonara!\n", arr[t2++]);
    else printf("Stack2 Underflow! Omo!\n");
}

void display() {
    printf("S1: "); for (int i = 0; i <= t1; i++) printf("%d ", arr[i]);
    printf("\nS2: "); for (int i = MAX - 1; i >= t2; i--) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int ch, x;
    printf("--- Multiple Stacks (Exam Q1) ---\n");
    while (1) {
        printf("\n1.Push1 2.Pop1 3.Push2 4.Pop2 5.Display 6.Exit: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Val: "); scanf("%d", &x); push1(x); break;
            case 2: pop1(); break;
            case 3: printf("Val: "); scanf("%d", &x); push2(x); break;
            case 4: pop2(); break;
            case 5: display(); break;
            case 6: exit(0);
        }
    }
}