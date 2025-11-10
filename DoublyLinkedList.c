//Doubly Linked List Operations

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at beginning.\n", value);
}

// Insert at end
void insertAtEnd(int value) {
    Node* newNode = createNode(value);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("%d inserted at end.\n", value);
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    printf("%d deleted from beginning.\n", temp->data);
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL; // list became empty
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = tail;
    printf("%d deleted from end.\n", temp->data);
    tail = tail->prev;
    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL; // list became empty
    free(temp);
}

// Traversal from beginning
void displayFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* current = head;
    printf("List (from beginning): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Traversal from end
void displayFromEnd() {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* current = tail;
    printf("List (from end): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Count elements
int countElements() {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Main menu
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display from Beginning\n");
        printf("6. Display from End\n");
        printf("7. Count Elements\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                displayFromBeginning();
                break;
            case 6:
                displayFromEnd();
                break;
            case 7:
                printf("Total elements: %d\n", countElements());
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
