#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} * start;

typedef struct node node;

void createList(int);
void display();
void removeAndAdd();

void main()
{
    int size;
    start = (node *)malloc(sizeof(node));
    printf("Enter the number of nodes: ");
    scanf("%d", &size);
    createList(size);
    printf("\nOriginal Node Elements\n");
    display();
    removeAndAdd();
    printf("\nAfter removing and adding the first element to the end\n");
    display();
}

void createList(int size)
{
    int i;
    node *traverse, *newNode;
    printf("Enter Node 1 data: ");
    scanf("%d", &start->data);
    traverse = start;
    start->link = NULL;
    for (i = 2; i <= size; i++)
    {
        newNode = (node *)malloc(sizeof(node));
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
    node *traverse;
    int i = 0;
    printf("\n\n");
    for (traverse = start; traverse != NULL; traverse = traverse->link)
    {
        printf("Node %d = %d\n", ++i, traverse->data);
    }
}

void removeAndAdd()
{
    node *end = start, *newNode=(node*)malloc(sizeof(node));

    //Finding last node 
    while (end->link != NULL)
    {
        end = end->link;
    }

    //Removing first node and adding at last
        newNode->data=start->data;
        newNode->link=NULL;
        end->link=newNode;
        start=start->link;
}