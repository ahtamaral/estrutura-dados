#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to perform a level-order traversal of the binary search tree
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* queue[1000]; // Assuming a maximum of 1000 nodes
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->value);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

int main() {
    struct Node* root = NULL;
    char input;
    int value = 0;

    while (1) {
        scanf(" %c", &input);

        if (input == 'i') {
            scanf("%d", &value);
            root = insert(root, value);
        } else if (input == 'p') {
            levelOrderTraversal(root);
            break;
        } else if (input == 'q') {
            break;
        } else {
            // printf("Entrada inválida. Insira 'i', 'p', ou 'q'.\n");
        }
    }

    return 0;
}