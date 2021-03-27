#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*start;

void createList(int);
void display();
void largeEnd();

void main(){
    int size;
    start=(struct node*)malloc(sizeof(struct node));
    printf("Enter the number of nodes: ");
    scanf("%d",&size);
    createList(size);
    printf("\nEntered Node Elements\n");
    display();
    largeEnd();
    printf("\nNode Elements after adding largest element at end\n");
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

    void largeEnd(){
        int max=start->data;
        struct node *end=start, *traverse=start, *prev=start;
        // Finding largest
        for(traverse=start; traverse!=NULL; traverse=traverse->link){
            if(max<traverse->data)
                max=traverse->data;
        }
        //Finding end 
        while(end->link!=NULL){
            end=end->link;
        }

        //Adding largest element at end
        for(traverse=start; traverse!=NULL; traverse=traverse->link){
            if(traverse->data==max){
                // if only 1 node
                if(end==start)
                    return;
                // if largest is at end
                if(end==traverse)
                    return;
                // if node 1 is largest
                if(prev==start && prev==traverse)
                    start=start->link;
                else
                    prev->link=traverse->link;
                end->link=traverse;
                traverse->link=NULL; 
            }
            prev=traverse;
        }

    }