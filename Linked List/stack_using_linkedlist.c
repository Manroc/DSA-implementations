//Author:-Manish Khadka 2022/11/30
//Stack implementation using linked list(dynamic)
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct blueprint{
int data;
struct blueprint *next;
};
typedef struct blueprint node;

node* top=NULL;
node* newnode=NULL;
node* temp=NULL;

node* getNode(int item)     //Function to create new node
{
newnode=(node*)malloc(sizeof(node));
newnode->data=item;
return newnode;
}

void push(int item)    //Function to push item
{
if(top==NULL)
{
newnode=getNode(item);
top=newnode;
top->next=NULL;
printf("Its the first item in stack. %d is pushed successfully.\n",top->data);
}
else{
newnode=getNode(item);
newnode->next=top;
top=newnode;
printf("%d is pushed successfully.\n",top->data);
}
}

void pop()  //Function to pop item from stack
{
if(top==NULL)
{
printf("The stack is empty. Cannot pop item.\n");
}
else
{
int hold;
hold=top->data;
temp=top;
top=temp->next;
free(temp);
printf("%d is popped item.\n",hold);
}
}

void peek()
{
if(top==NULL)
{
printf("Stack is empty.\n");
}
else
{
int item;
item=top->data;
printf("The item on top of the stack is %d\n",item);
}
}

void display()
{
	if(top==NULL)
	printf("nothing to display. The stack is empty\n");
	else
	{printf("Items in stack are:-\n");
		temp=top;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
	
}
int main()
{
int choice=0;
printf("Stack implementation using linked list\n");
while(choice!=4){
printf("1)PUSH\n2)POP\n3)PEEK\n4)Exit\nYour choice:-");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
int item;
printf("Enter item you want to push:- ");
scanf("%d",&item);
push(item);
break;
}
case 2:
{
pop();
break;
}
case 3:
{
peek();
break;
}
case 4:{
	display();
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
