// C Program to reverse a linked list

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the linked list
void addNode(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Recursive function to reverse the linked list
struct Node *reverseListRecursive(struct Node *head)
{
    // Base case: empty list or single node
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Recursively reverse the rest of the list
    struct Node *rest = reverseListRecursive(head->next);

    // Adjust pointers
    head->next->next = head;
    head->next = NULL;

    // Return the new head of the reversed list
    return rest;
}

// Function to print the linked list
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    // Adding nodes to the linked list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);

    // Print the initial linked list
    printf("Initial Linked List:\n");
    printList(head);

    // Reverse the linked list
    head = reverseListRecursive(head);

    // Print the reversed linked list
    printf("Reversed Linked List:\n");
    printList(head);

    return 0;
}