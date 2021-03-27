#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*start;

void createList(int);
void display();
void removeAdd();

void main(){
    int size;
    start=(struct node*)malloc(sizeof(struct node));
    printf("Enter the number of nodes: ");
    scanf("%d",&size);
    createList(size);
    printf("\nEntered Node Elements\n");
    display();
    removeAdd();
    printf("\nNode Elements after removing first element and adding at end\n");
    display();
}

void createList(int size){
    int i;
    struct node *traverse, *newNode;
    printf("Enter Node 1 data: ");
    scanf("%d",&start->data);
    start->link=NULL;
    traverse=start;
    for(i=2;i<=size;i++){
        newNode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Node %d data: ",i);
        scanf("%d",&newNode->data);
        newNode->link=NULL;
        traverse->link=newNode;
        traverse=traverse->link;
    }
}
    void display(){
        int i=0;
        struct node *traverse;
        printf("\n");
        for(traverse=start; traverse!=NULL; traverse=traverse->link)
            printf("Node %d = %d\n",++i,traverse->data);
        }

    void removeAdd(){
        struct node *end=start, *newStart;
        while(end->link!=NULL){
            end=end->link;
        }

        // If only one node
        if(end==start)
            return;
        // Removing first node and adding it to the last node
        newStart = start->link;
        end->link=start;
        start->link=NULL;
        start=newStart;

    }
