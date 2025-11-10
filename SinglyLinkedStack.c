//Singly Linked Stack-Creation,Insertion,Deletion,Traversal,count

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;  // Stack top pointer

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Push (Insertion)
void push(int value) {
    Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}

// Pop (Deletion)
void pop() {
    if (top == NULL) {
        printf("Stack is empty! Cannot pop.\n");
        return;
    }
    Node* temp = top;
    printf("%d popped from stack\n", top->data);
    top = top->next;
    free(temp);
}

// Traversal (Display stack elements)
void display() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    Node* current = top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Count number of elements
int count() {
    int cnt = 0;
    Node* current = top;
    while (current != NULL) {
        cnt++;
        current = current->next;
    }
    return cnt;
}

// Main menu
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Singly Linked Stack Operations ---\n");
        printf("1. Push (Insertion)\n");
        printf("2. Pop (Deletion)\n");
        printf("3. Display (Traversal)\n");
        printf("4. Count elements\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Total elements in stack: %d\n", count());
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
