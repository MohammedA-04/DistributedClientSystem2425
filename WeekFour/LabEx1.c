// Design C program to:
// 1. create node
// 2. add node at the end
// 3. delete node with (value)
// 4. display list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // using (->) to access members of struct pointer
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Add node at the end of LL
void addNode(struct Node **head, int value)
{

    struct Node *newNode = createNode(value);

    // if head is null set to new node
    if (*head == NULL)
    {
        *head = newNode;
    }

    // if head is not null linearly traverse to the end of LL
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            // (->) accesses members of [struct] Node* ptr
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(struct Node **head, int value)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    // If node to be removed is head
    /* Example

    temp -> [1] -> [2] -> [3] -> NULL
    head -> [1] -> [2] -> [3] -> NULL
    prev -> NULL

    temp -> [1] -> [2] -> [3] -> NULL (free'd)
    head -> [2] -> [3] -> NULL
    prev -> NULL
    */

    if (temp != NULL && temp->data == value)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for node to be removed
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    // if vale was not found
    if (temp == NULL)
    {
        printf("Node with %d not found\n", value);
        return;
    }

    // unlink the node from lineked list
    prev->next = temp->next;
    free(temp);

    // So here prev: v1 only
    // Then v1.next = equals temp.next
}

// function to print linked list
void printList(struct Node *head)
{
    // *temp will hold copy of head node
    struct Node *temp = head;

    // using temp we loop and print until not null
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next; // Move to the next node
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    // Adding nodes to the linked list
    addNode(&head, 1); // mem adr of *head ptr
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);

    // print LL
    printf("Initial Linked List\n");
    printList(head);

    // deleting a node with value 2
    deleteNode(&head, 2);

    // print updated LL
    printf("Linked List after deletion\n");
    printList(head);

    return 0;
}