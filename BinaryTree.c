//Binary Tree-Creation,Insertion,Deletion,Traversal(inorder,preorder,postorder)

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* createTree() {
    int value,choice;
    printf("Enter node value: ");
    scanf("%d", &value);
    Node* newNode = createNode(value);
    printf("Do %d have left node(yes-1,no-0):", value);
    scanf("%d", &choice);
    if(choice==1){
        newNode->left = createTree();
    }
    return newNode;
}
void insert(Node* root, int value) {
    int choice;
    if(root == 0){
        return;
    }
    printf("Do %d have left node(yes-1,no-0):", root->data);
    scanf("%d", &choice);
    if(choice == 0 && !root->left){
        root->!left = createNode(value);
        return;
    }
    else if(choice == 1 && root->left){
        insert(root->left, value);
        return;
    }
    printf("Do %d have right node(yes-1,no-0):", root->data);
    scanf("%d", &choice);
    if(choice == 0 && !root->right){
        root->right = createNode(value);
        return;
    }
    else if(choice == 1 && root->right){
        insert(root->right, value);
        return;
    }
}

void *delete(Node* root, int value) {
    if (!root) {
        return NULL;
    }
    if(root->data == value) {
        // Node with only one child or no child
        if (!root->left && !root->right) {
            free(root);
            return  NULL; 
    }
    if(root-> left && !root->right) {
        Node* temp = root->left;
        free(root);
        return temp;
    }
    if(!root-> left && root->right) {
        Node* temp = root->right;
        free(root);
        return temp;
    }
    Node* temp = root->right;
    while(temp->left) {
        temp = temp->left;
    }
    root->data = temp->data;
    root->right = delete(root->right, temp->data);
        return root;
    }
    root->left = delete(root->left, value);
    root->right = delete(root->right, value);
    return root;
}

// Inorder Traversal
void inorder(Node* root) {
    if(!root){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

//Preorder Traversal
void preorder(Node* root) {
    if(!root){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

//Postorder Traversal
void postorder(Node* root) {
    if(!root){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = NULL;
    int choice, value;
    while (1) {
        printf("\nBinary Tree Operations Menu:\n");
        printf("1. Create Tree\n");
        printf("2. Insert Node\n");
        printf("3. Delete Node\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                root = createTree();
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(root, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(root, value);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
