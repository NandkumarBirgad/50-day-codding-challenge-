#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to delete the k-th node (0-based index)
struct Node* deleteKthNode(struct Node* head, int k) {
    if (head == NULL) return head;

    // If head needs to be removed
    if (k == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    for (int i = 0; current != NULL && i < k - 1; i++) {
        current = current->next;
    }

    // If position is more than number of nodes
    if (current == NULL || current->next == NULL)
        return head;

    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int i, k, value;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    // Input 10 elements
    for (i = 0; i < 10; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Input the position to delete
    scanf("%d", &k);

    // Delete the k-th node
    head = deleteKthNode(head, k);

    // Print updated list
    printList(head);

    return 0;
}