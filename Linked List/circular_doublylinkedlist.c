//Author:- Manish Khadka 2022/12/2
//Circular doubly linked list 
//STACK AS AN ADT
//INFIX TO POSTFIX
//QUEUE
//PRIORITY QUEUE 
//ARRAY LIST
//SINGLE LINKED LIST,DOUBLE,CIRCULAR
//STACK QUEUE USING SINGLE LINKED LIST
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
struct node* pre;
int data;
struct node* next;
};
typedef struct node nodetype;
nodetype* head=NULL;
nodetype* tail=NULL;
nodetype* temp=NULL;
nodetype* newnode=NULL;


nodetype* getNode(int item)
{
newnode=(nodetype*)malloc(sizeof(nodetype));
newnode->data=item;
return newnode;
}

void insertFirst(int item)
{
newnode=getNode(item);
if(head==NULL)
{
head=newnode;
tail=newnode;
newnode->next=newnode;
newnode->pre=newnode;
/*
head->data=item;
head->next=head;
tail=head;
head->pre=tail;*/
printf("%d is inserted in circular doubly linked list.\n",newnode->data);
}
else
{
	head->pre=newnode;
	tail->next=newnode;
	newnode->pre=tail;
	newnode->next=head;
	head=newnode;
	
	/*
	head->pre=newnode;
	newnode->next=head;
	newnode->pre=tail;
	tail->next=newnode;
	head=newnode;
	head->data=item;
	* */
	printf("%d is inserted in beginning of circular doubly linked list.\n",newnode->data);
}
}

void insertLast(int item)
{
	newnode=getNode(item);
if(head==NULL)
{
	head=newnode;
	tail=newnode;
	newnode->next=newnode;
	newnode->pre=newnode;
}
else
{
	tail->next=newnode;
	newnode->pre=tail;
	newnode->next=head;
	head->pre=newnode;
	tail=newnode;
	printf("%d is inserted at tail of circular doubly linked list",tail->data);
}
}
void deleteFirst()
{
	if(head==NULL)
	printf("Nothing to delete.\n");
	else if(head==tail)
	{
		temp=head;
		head=tail=NULL;
		free(temp);
		printf("Node deleted. Now the list is empty.\n");
	}
	else
	{
		temp=head;
		head=head->next;
		head->pre=tail;
		tail->next=head;
		free(temp);
		printf("Last node deleted.\n");
	}
}

void deleteLast()
{
	if(head==NULL)
	printf("Nothing to delete.\n");
	else if(head==tail)
	{
	temp=head;
	head=tail=NULL;
	free(temp);
	printf("Node deleted. Now the list is empty.\n");
	}
	else
	{
		temp=tail->pre;
		temp->next=head;
		free(tail);
		tail=temp;
		printf("Last node is deleted.\n");
	}
}

void traverseFirstToLast()
{
	if(head==NULL)
	printf("The circular linked list is empty.\n");
	else
	{
		temp=head;
		printf("The items in list are:-\n");
		while(temp!=head)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}	
	}
}

void traverseLastToFirst()
{
	if(head==NULL)
	printf("The circular doubly linked list is empty.\n");
	else
	{
		temp=head->pre;
		printf("The items in list from last to first are:-\n");
		while(temp!=head)
		{
			printf("%d\t",temp->data);
			temp=temp->pre;
		}
	}
}
		
int main()
{
int choice=0;
printf("Doubly linked list implementation using C\n");
while(choice!=7)
{
printf("1)Insert at first\n2)Insert at last\n3)Delete at first\n4)Delete at last\n5)Traverse from first to last\n6)Traverse from last to first\n)7Exit\nYour choice:-");
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
traverseFirstToLast();
break;
}
case 7:
{
	traverseLastToFirst();
{
	
case 8:
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

