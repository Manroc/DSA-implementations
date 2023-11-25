//Author:- Manish Khadka 2022/12/1
//Impelementation of doubly linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
struct node *pre;
int data;
struct node *next;
};
typedef struct node nodetype;
nodetype *head=NULL;
nodetype *tail=NULL;
nodetype *newnode=NULL;
nodetype *temp=NULL;

nodetype* getNode()
{
newnode=(nodetype*)malloc(sizeof(nodetype));
newnode->next=NULL;
newnode->pre=NULL;
return newnode;
}

void insertFirst(int item)
{
	newnode=getNode(item);
if(head==NULL)
{
	head=newnode;
tail=head;
head->data=item;

printf("%d is inserted in doubly linked list.\n",head->data);
}
else
{
newnode->next=head;
head->pre=newnode;
head=newnode;
head->data=item;
printf("%d is inserted in beginning of doubly linked list.\n",head->data);
}
}

void insertLast(int item)
{
if(head==NULL)
{
insertFirst(item);
}
else
{
newnode=getNode();
tail->next=newnode;
newnode->pre=tail;
newnode->next=NULL;
tail=newnode;
tail->data=item;
printf("%d is inserted in end of doubly linked list.\n",tail->data);
}
}

void deleteFirst()
{
if(head==NULL)
{
printf("Nothing to delete. The list is empty.\n");
}
else if(head==tail)
{
temp=head;
head=tail=NULL;
free(temp);
printf("First node is deleted and now the doulby linked list is empty.\n");
}
else
{
temp=head;
head=temp->next;
free(temp);
head->pre=NULL;
printf("First node is deleted.\n");
}
}

void deleteLast()
{
if(head==NULL)
printf("Nothing to delete. The list was empty.\n");
else if(head==tail)
{
temp=head;
head=tail=NULL;
free(temp);
printf("Node is deleted, Now the list is empty.\n");
}
else
{
temp=tail;
temp=temp->pre;
free(tail);
tail=temp;
tail->next=NULL;
printf("The last node is deleted.\n");
}
}

void traverse_first_to_last()
{
temp=head;
printf("Data in linked list from first to last are:-\n");
while(temp->next!=NULL)
{
printf("%d\t",temp->data);
temp=temp->next;
}
printf("%d\n",temp->data);
}

void traverse_last_to_first()
{
temp=tail;
printf("Data in linked list from last to first are:-\n");
while(temp->pre!=NULL)
{
printf("%d\t",temp->data);
temp=temp->pre;
}
printf("%d\n",temp->data);
}

int main()
{
int choice=0;
printf("Doubly linked list implementation using C\n");
while(choice!=7)
{
printf("1)insert at first\n2)insert at last\n3)delete at first\n4)delete at last\n5)Traverse from head to tail\n6)Traverse from tail to head\n7)Exit\nYour choice:-");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
int item;
printf("Enter item you want to insert:- ");
scanf("%d",&item);
insertFirst(item);
break;
}
case 2:
{
	int item;
printf("Enter item you want to insert:- ");
scanf("%d",&item);
insertLast(item);
break;
}
case 3:
{
deleteFirst();
break;
}
case 4:{
deleteLast();
break;
}
case 5:
{
traverse_first_to_last();
break;
}
case 6:
{
traverse_last_to_first();
break;
}
case 7:
{	
	printf("Exiting....");
	break;
}
default:
{
printf("Invalid choice.\n");
}
};
}
return 0;
}
