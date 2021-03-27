#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*start;

void createList(int);
void display();
void largeSmall();

void main(){
    int size;
    start=(struct node*)malloc(sizeof(struct node));
    printf("Enter the number of nodes: ");
    scanf("%d",&size);
    createList(size);
    display();
    largeSmall();
}

void createList(int size){
    int i;
    struct node *traverse, *newNode;
    printf("Enter Node 1 data: ");
    scanf("%d",&start->data);
    traverse=start;
    start->link=NULL;
    for(i=2; i<=size; i++){
        newNode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Node %d data: ",i);
        scanf("%d",&newNode->data);
        newNode->link=NULL;
        traverse->link=newNode;
        traverse=traverse->link;
    }
    printf("\nLinked list Created\n\n");
}


void display(){
    struct node *traverse;
    int i=0;
    printf("\nNode Elements are\n");
    for(traverse=start; traverse!=NULL; traverse=traverse->link){
        printf("Node %d = %d\n",++i,traverse->data);
    }
}


void largeSmall(){
    int max, min;
    struct node *traverse;
    max=start->data;
    min=start->data;
    //Finding the largest and smallest element
    for(traverse=start; traverse!=NULL; traverse=traverse->link){
        if(max<traverse->data)
            max=traverse->data;
        if(min>traverse->data)
            min=traverse->data;
    }

    printf("\n\nLargest = %d\nSmallest = %d\n\n",max,min);
}
