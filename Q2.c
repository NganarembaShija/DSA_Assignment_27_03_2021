#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} * start;

void createList(int);
void display();
void swap();

void main()
{
    int size;
    start = (struct node *)malloc(sizeof(struct node));
    printf("Enter the number of nodes: ");
    scanf("%d", &size);
    createList(size);
    printf("\nBefore Swapping\n");
    display();
    swap();
    printf("\nAfter Swapping\n");
    display();
}

void createList(int size)
{
    int i;
    struct node *traverse, *newNode;
    printf("Enter Node 1 data: ");
    scanf("%d", &start->data);
    traverse = start;
    start->link = NULL;
    for (i = 2; i <= size; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Node %d data: ", i);
        scanf("%d", &newNode->data);
        newNode->link = NULL;
        traverse->link = newNode;
        traverse = traverse->link;
    }
    printf("\nList Created\n\n");
}

void display()
{
    struct node *traverse;
    int i = 0;
    printf("\n\n");
    for (traverse = start; traverse != NULL; traverse = traverse->link)
    {
        printf("Node %d = %d\n", ++i, traverse->data);
    }
}

void swap()
{
    int swap;
    struct node *end = start;

    //Finding last node 
    while (end->link != NULL)
    {
        end = end->link;
    }

    //Swapping the first and last node
        swap=start->data;
        start->data=end->data;
        end->data=swap;
}
