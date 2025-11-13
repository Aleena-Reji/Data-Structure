//Singly Linked List-Creation,Insertion,Deletion,Traversal,count

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insertion
void insert(struct Node** head,int data) {
    struct Node* newNode = createNode(data);
   if(*head == NULL){
    *head = newNode;
    return;
   }
   struct Node*temp = *head;
   while(temp->next != NULL){
    temp = temp->next;
   }
    temp->next = newNode;
}

// Deletion
void delete(struct Node** head,int key) {
    struct Node* temp = *head, *prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Changed head
        free(temp);         // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf(" %d not found in stack!\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Traversal 
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d\t ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Count number of elements
int count() {
    int cnt = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// Main menu
int main() {
    struct Node* head = NULL;
    int choice, value;
    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display (Traversal)\n");
        printf("4. Count elements\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(&head, value);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                printf("Total elements in list: %d\n", count(head));
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
 return 0;
}
