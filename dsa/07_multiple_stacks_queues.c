#include <stdio.h>
#include <stdlib.h>

// ================= GLOBAL VARIABLES =================

// --- Multiple Stacks (Dynamic) ---
int *stack;
int st_size = 10;
int top1 = -1;
int top2; // Initialized in init_stack

// --- Multiple Queues (Fixed Partition) ---
int *queue;
int q_size = 10;
int f1 = -1, r1 = -1;
int f2, r2; // Initialized in init_queue
int b1, b2; // Boundaries for Queue 1 and Queue 2

// ================= STACK FUNCTIONS =================

void init_stack() {
    stack = (int*)malloc(st_size * sizeof(int));
    if (!stack) {
        printf("Stack Memory allocation failed!\n");
        exit(1);
    }
    top2 = st_size;
    printf("Initialized Dual Stack with size %d\n", st_size);
}

void resize_stack() {
    int old_size = st_size;
    st_size *= 2;
    int *new_stack = (int*)realloc(stack, st_size * sizeof(int));
    if (!new_stack) {
        printf("Stack Memory reallocation failed!\n");
        exit(1);
    }
    stack = new_stack;
    
    // Shift Stack 2 elements to the end of the new array
    int i;
    for (i = 0; i < (old_size - top2); i++) {
        // top2 in old array was at index 'top2'
        // We need to move elements from old_top2...old_size-1
        // to new_size-(count)...new_size-1
        
        // Simpler loop:
        // iterate from old_size-1 down to top2
        // move stack[k] to stack[k + old_size] 
        // (since new_size = 2*old_size, the gap is old_size)
    }
    
    // Correct shifting logic
    for (i = old_size - 1; i >= top2; i--) {
        stack[i + old_size] = stack[i];
    }
    
    top2 += old_size;
    printf("Stack resized from %d to %d.\n", old_size, st_size);
}

void push1() {
    if (top1 == top2 - 1) {
        resize_stack();
    }
    
    int val;
    printf("Enter value for Stack 1: ");
    scanf("%d", &val);
    top1++;
    stack[top1] = val;
    printf("%d pushed to Stack 1.\n", val);
}

void push2() {
    if (top1 == top2 - 1) {
        resize_stack();
    }
    
    int val;
    printf("Enter value for Stack 2: ");
    scanf("%d", &val);
    top2--;
    stack[top2] = val;
    printf("%d pushed to Stack 2.\n", val);
}

void pop1() {
    if (top1 >= 0) {
        printf("Popped from Stack 1: %d\n", stack[top1]);
        top1--;
    } else {
        printf("Stack 1 Underflow!\n");
    }
}

void pop2() {
    if (top2 < st_size) {
        printf("Popped from Stack 2: %d\n", stack[top2]);
        top2++;
    } else {
        printf("Stack 2 Underflow!\n");
    }
}

void display_stack1() {
    int i;
    if (top1 >= 0) {
        printf("Stack 1: ");
        for (i = top1; i >= 0; i--) printf("%d ", stack[i]);
        printf("\n");
    } else {
        printf("Stack 1 is empty.\n");
    }
}

void display_stack2() {
    int i;
    if (top2 < st_size) {
        printf("Stack 2: ");
        for (i = top2; i < st_size; i++) printf("%d ", stack[i]);
        printf("\n");
    } else {
        printf("Stack 2 is empty.\n");
    }
}

// ================= QUEUE FUNCTIONS =================

void init_queue() {
    queue = (int*)malloc(q_size * sizeof(int));
    if (!queue) {
        printf("Queue Memory allocation failed!\n");
        exit(1);
    }
    
    // Partitioning the array into two equal halves
    // Queue 1: 0 to (q_size/2) - 1
    // Queue 2: (q_size/2) to q_size - 1
    
    b1 = q_size / 2;      // Boundary for Q1 (Exclusive)
    b2 = q_size;          // Boundary for Q2 (Exclusive)
    
    // Initialize pointers
    f1 = -1; r1 = -1;
    f2 = b1 - 1; r2 = b1 - 1; // Start relative to the second partition
    
    printf("Initialized Dual Queue with size %d\n", q_size);
    printf("Queue 1 Capacity: %d\n", b1);
    printf("Queue 2 Capacity: %d\n", b2 - b1);
}

void enqueue1() {
    if (r1 == b1 - 1) {
        printf("Queue 1 Overflow!\n");
        return;
    }
    
    int val;
    printf("Enter value for Queue 1: ");
    scanf("%d", &val);
    
    if (f1 == -1) f1 = 0;
    r1++;
    queue[r1] = val;
    printf("%d enqueued to Queue 1.\n", val);
}

void dequeue1() {
    if (f1 == -1 || f1 > r1) {
        printf("Queue 1 Underflow!\n");
        // Reset if empty
        f1 = -1; r1 = -1;
        return;
    }
    
    printf("Dequeued from Queue 1: %d\n", queue[f1]);
    f1++;
    if (f1 > r1) { // Reset if became empty
        f1 = -1; r1 = -1;
    }
}

void display_q1() {
    if (f1 == -1 || f1 > r1) {
        printf("Queue 1 is empty.\n");
        return;
    }
    printf("Queue 1: ");
    for (int i = f1; i <= r1; i++) printf("%d ", queue[i]);
    printf("\n");
}

void enqueue2() {
    if (r2 == b2 - 1) {
        printf("Queue 2 Overflow!\n");
        return;
    }
    
    int val;
    printf("Enter value for Queue 2: ");
    scanf("%d", &val);
    
    // Initial state check
    if (f2 == b1 - 1) f2 = b1;
    
    r2++;
    queue[r2] = val;
    printf("%d enqueued to Queue 2.\n", val);
}

void dequeue2() {
    if (f2 == b1 - 1 || f2 > r2) {
        printf("Queue 2 Underflow!\n");
        f2 = b1 - 1; r2 = b1 - 1;
        return;
    }
    
    printf("Dequeued from Queue 2: %d\n", queue[f2]);
    f2++;
    if (f2 > r2) { // Reset
        f2 = b1 - 1; r2 = b1 - 1;
    }
}

void display_q2() {
    if (f2 == b1 - 1 || f2 > r2) {
        printf("Queue 2 is empty.\n");
        return;
    }
    printf("Queue 2: ");
    for (int i = f2; i <= r2; i++) printf("%d ", queue[i]);
    printf("\n");
}

// ================= MENUS =================

int main() {
    init_stack();
    init_queue();
    
    int choice;
    while (1) {
        printf("\n=== MULTIPLE STACKS & QUEUES UNIFIED MENU ===\n");
        printf("--- Stacks (Dynamic Array 1) ---\n");
        printf("1. Push Stack 1\n");
        printf("2. Pop Stack 1\n");
        printf("3. Push Stack 2\n");
        printf("4. Pop Stack 2\n");
        printf("5. Display Stacks\n");
        printf("\n--- Queues (Fixed Array 2) ---\n");
        printf("6. Enqueue Queue 1\n");
        printf("7. Dequeue Queue 1\n");
        printf("8. Enqueue Queue 2\n");
        printf("9. Dequeue Queue 2\n");
        printf("10. Display Queues\n");
        printf("\n11. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            // Stack Operations
            case 1: push1(); break;
            case 2: pop1(); break;
            case 3: push2(); break;
            case 4: pop2(); break;
            case 5: display_stack1(); display_stack2(); break;
            
            // Queue Operations
            case 6: enqueue1(); break;
            case 7: dequeue1(); break;
            case 8: enqueue2(); break;
            case 9: dequeue2(); break;
            case 10: display_q1(); display_q2(); break;
            
            case 11: 
                free(stack); 
                free(queue); 
                printf("Exiting...\n"); 
                exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
