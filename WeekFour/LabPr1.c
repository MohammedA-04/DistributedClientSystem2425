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

// Function to merge two linked lists
struct Node *mergeLinkedLists(struct Node **head1, struct Node **head2)
{
    if (*head1 == NULL)
    {
        return *head2;
    }

    if (*head2 == NULL)
    {
        return *head1;
    }

    struct Node *mergedHead = NULL;
    struct Node **lastPtrRef = &mergedHead;

    while (*head1 != NULL && *head2 != NULL)
    {
        if ((*head1)->data <= (*head2)->data)
        {
            *lastPtrRef = *head1;
            *head1 = (*head1)->next;
        }
        else
        {
            *lastPtrRef = *head2;
            *head2 = (*head2)->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    // Attach the remaining nodes
    if (*head1 != NULL)
    {
        *lastPtrRef = *head1;
    }
    else
    {
        *lastPtrRef = *head2;
    }

    return mergedHead;
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
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    // Adding nodes to the first linked list
    addNode(&head1, 1);
    addNode(&head1, 3);
    addNode(&head1, 5);

    // Adding nodes to the second linked list
    addNode(&head2, 2);
    addNode(&head2, 4);
    addNode(&head2, 6);

    // Print the initial linked lists
    printf("First Linked List:\n");
    printList(head1);

    printf("Second Linked List:\n");
    printList(head2);

    // Merge the linked lists
    struct Node *mergedHead = mergeLinkedLists(&head1, &head2);

    // Print the merged linked list
    printf("Merged Linked List:\n");
    printList(mergedHead);

    return 0;
}