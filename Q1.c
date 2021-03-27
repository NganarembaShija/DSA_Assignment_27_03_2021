#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*start;

void createList(int);
void display();
void largestEnd();

void main(){
    int size;
    start=(struct node*)malloc(sizeof(struct node));
    printf("Enter the number of nodes: ");
    scanf("%d",&size);
    createList(size);
    printf("\nOriginal node elements\n");
    display();
    largestEnd();
    printf("\nAfter moving the largest element to the end\n");
    display();
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
    printf("\nList Created\n\n");
}


void display(){
    struct node *traverse;
    int i=0;
    printf("\n\n");
    for(traverse=start; traverse!=NULL; traverse=traverse->link){
        printf("Node %d = %d\n",++i,traverse->data);
    }
}


void largestEnd(){
    int max, swap;
    struct node *traverse, *end=start, *prev=start, *next=start, *tprev;
    max=start->data; // Initializing largest element as first node data

    //Finding the maximum number
    for(traverse=start; traverse!=NULL; traverse=traverse->link){
        if(max<traverse->data){
            max=traverse->data;
        }
    }

    //Finding last node and the node before the last node
    while(end->link!=NULL){
        prev=end;
        end=end->link;
    }

    // If only one node
    if(end==start){
        return;
    }
    else if(end==start->link){ // For two nodes only
        swap=end->data;
        end->data=start->data;
        start->data=swap;
        return;
    }
    // For no. of nodes>2
    //Moving the Largest element to the end of the list
    for(traverse=start; traverse!=NULL; traverse=traverse->link){
        if(traverse->data==max){

            if(traverse==start) // if the largest element is at start position
                start=traverse->link;
            else if(prev==traverse) // if the largest element is at last-second node
                tprev->link=traverse;
            else if(traverse!=end) // if the largest element is not the last node
                tprev->link = traverse->link;

            if(traverse==end) // if the largest element is at the last node ;
                return;

            swap=end->data; //Copying last node data
            end->data=traverse->data; //Assigning the largest element to last node
            traverse->data = swap; //Assigning the last node data to the node which has largest element before
            prev->link=traverse; //Connecting the last second node to the node which has the last node data
            traverse->link = end; 
            break;
        }
        tprev=traverse;
    }
}
