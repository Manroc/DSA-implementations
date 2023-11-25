//Author:- Manish Khadka 2022/11/30
//Circular linked list as an ADT
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
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

void insertbeg(int item)
{
newnode=getNode(item);
if(head==NULL)
{
head=newnode;
tail=newnode;
head->next=head;
printf("This is first node. %d is inserted successfully.\n",head->data);
}
else
{
newnode->next=head;
head=newnode;
tail->next=newnode;
printf("%d is inserted at beginning successfully.",head->data);
}
}

void insertEnd(int item)
{
newnode=getNode(item);
if(head==NULL)
{
head=newnode;
tail=newnode;
head->next=head;
printf("%d is inserted at end.",tail->data);
}
else
{
tail->next=newnode;
tail=newnode;
tail->next=head;
printf("%d is inserted at end.",tail->data);
}
}

void deleteFirst()
{
if(head==NULL)
{
printf("The List is empty. Nothing to delete.");
}
else if(head==tail)
{
temp=head;
free(temp);
head=tail=NULL;
printf("The node is deleted. Now the list is empty.\n");
}
else
{
	tail->next=head->next;
	temp=head;
	head=head->next;
	free(temp);
	
	
	
/*temp=head;
temp=temp->next;
tail->next=temp;
head=temp;
free(temp);*/
printf("The first node is deleted.\n");
}
}

void deleteLast()
{
if(head==NULL)
{
printf("The list is Empty. Nothing to delete.\n");
}
else if(head==tail)
{
temp=head;
free(temp);
head=tail=NULL;
printf("Last node is deleted and now the list is empty.\n");
}
else
{
temp=tail;
while(temp->next!=tail)
{
temp=temp->next;
}
temp->next=head;
free(tail);
tail=temp;
printf("Last node is deleted.\n");
}
}
void traverse()
{
	if(head==NULL)
	printf("The list is empty");
	else{
temp=head;
printf("The items in list are:- \n");
while(temp->next!=head)
{
printf("%d\t",temp->data);
temp=temp->next;
}
printf("%d\n",temp->data);
}
}

int main()
{
int choice=0;
printf("Circular linked list implementation using C\n");
while(choice!=6){
printf("1)insert at first\n2)insert at last\n3)delete at first\n4)delete at last\n5)Traverse\n6)Exit\nYour choice:-");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
int item;
printf("Enter item you want to insert:- ");
scanf("%d",&item);
insertbeg(item);
break;
}
case 2:
{
	int item;
printf("Enter item you want to insert:- ");
scanf("%d",&item);
insertEnd(item);
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
traverse();
break;
}
case 6:
{
	printf("Exiting....");
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

