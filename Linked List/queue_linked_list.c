//Author: Manish Khadka 2022/11/30
//Linear Queue using linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct blueprint{
int data;
struct blueprint *next;
};
typedef struct blueprint node;

node* front=NULL;
node* rear=NULL;

node* getNode(int item)
{
    node* newnode;
newnode=(node*)malloc(sizeof(node));
newnode->data=item;
return newnode;
}

void enqueue(int item)
{
if(front==NULL && rear==NULL)
{
    node* newnode;
newnode=getNode(item);
front=rear=newnode;
rear->next=NULL;
printf("%d item is successfully enqueued.\n",rear->data);
}
else{
        node* newnode;
newnode=getNode(item);
rear->next=newnode;
rear=newnode;
rear->next=NULL;
printf("%d item is successfully enqueued.\n",rear->data);
}
}

void dequeue()
{
    if(front==NULL && rear==NULL)
    {
        printf("The queue is empty. Nothing to dequeue.\n");
    }
    else if(front->next==NULL)
    {
        int hold;
        hold=front->data;
        node* temp;
        temp=front;
        free(temp);
        front=rear=NULL;
        printf("Dequeued successfully);
    }
    else
    {
        int hold;
        node* temp=NULL;
        hold=front->data;
        temp=front;
        front=temp->next;
        free(temp);
        printf("Dequeued item is %d.\n",hold);
    }
}

void traverse()
{
    if(front==NULL && rear==NULL)
    {
        printf("The queue is Empty.\n");
    }
    else
    {
    node* temp;
    temp=front;
    printf("Items in queue from front to last are:- \n");
    while(temp->next!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
    }
    printf("\n");
}

int main()
{
int choice=0;
printf("Queue implementation using linked list\n");
while(choice!=4){
printf("1)Enqueue\n2)Dequeue\n3)Traverse\n4)Exit\nYour choice:-");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
int item;
printf("Enter item you want to enqueue:- ");
scanf("%d",&item);
enqueue(item);
break;
}
case 2:
{
dequeue();
break;
}
case 3:
{
traverse();
break;
}
case 4:{
printf("Exiting...\n");
break;
}
default:
{
printf("Invalid choice.\n");
}
}
}
return 0;
}
