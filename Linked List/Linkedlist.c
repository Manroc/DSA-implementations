//Author:- Manish 2022/11/29
//Program that implements linked list in C
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct blueprint{
struct blueprint* next;
int data;
};
typedef struct blueprint node;
node* newnode=NULL;
node* head=NULL;
node* temp=NULL;

node* getNode(int item)
{
newnode=(node* )malloc(sizeof(node));
newnode->data=item;
newnode->next=NULL;
return newnode;
}

void insertAtFirst(int item)
{
    newnode=getNode(item);
    if(head==NULL)
    {
        head=newnode;
        printf("%d is inserted successfully.\n",head->data);
    }
    else{
    temp=head;
    newnode->next=temp;
    head=newnode;
     printf("%d is inserted successfully.\n",head->data);
    }
}
void insertAtLast(int item)
{
    if(head==NULL)
		insertAtFirst(item);
    else{
		newnode=getNode(item);
        temp=head;
        while(temp->next!=NULL)
             temp=temp->next;
        temp->next=newnode;
         printf("Inserting at last node. %d is inserted successfully.\n",newnode->data);
        }
}
void insertAt(int pos,int item)
{
    if(pos== 1 && head==NULL)
   {
        insertAtFirst(item);
    }    
    else
    {
        newnode=getNode(item);
        temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        printf("%d is inserted at positon %d successfully.\n",newnode->data,pos);
	}
}
void deleteAtFirst()
{
if(head==NULL)
{
    printf("The linked list is empty and doesn't contain any node to delete.");
}
else if(head->next==NULL)
{
    temp=head;
    free(temp);
    head=NULL;
    printf("First node deleted and now node is empty.\n");
}
else{
    temp=head;
    head=temp->next;
    printf("Deleting first node. The node contains the item:- %d\n",temp->data);
    free(temp);
    printf("Node deleted.\n");
}
}

void deleteAtLast()
{
    if(head==NULL)				
{
    printf("The linked list is empty and doesn't contain any node to delete.");
}
else if(head->next==NULL)			//if one node in linked list
{
 
    temp=head;
    free(temp);
    head=NULL;
    printf("First node deleted and now node is empty.\n");
}
else 
{ 
  
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    printf("Deleting node.The node contains the data:- %d\n",temp->next->data);
    free(temp->next);
    temp->next=NULL;
    printf("Last node deleted.\n");
}
}
void deleteAtPos(int pos)
{
    if(head==NULL)
{
    printf("The linked list is empty and doesn't contain any node to delete.");
}
else if(head->next==NULL && pos==1)
{
    temp=head;
    free(temp);
    head=NULL;
    printf("Node of position 1 deleted and now node is empty.\n");
}
else{
       
        node* hold;
        temp=head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    printf("Deleting node of position %d and the node contains the data:- %d\n",pos,temp->next->data);
    hold=temp->next->next;
    free(temp->next);
    temp->next=hold;
    printf("Node deleted.\n");
    }
}

void traverse(){
temp=head;
printf("The values in linked list are:- \n");
while(temp->next!=NULL)
{
    printf("%d\t",temp->data);
    temp=temp->next;
}
printf("%d",temp->data);
}

void search(int item)
{
   if(head==NULL)
   printf("The list is empty, Can't search\n");
   else{
    temp=head;
    int i=0;
    while(temp->next!=NULL)
    {
        i++;
        if(temp->data==item)
            printf("%d found at position %d.\n",temp->data,i);
        temp=temp->next;    
    }
   }
}
int main()
{
int choice;
do{
    printf("\n1)Insert at beginning of node\n2)Insert at End of node\n3)Insert node at desired position\n4)Delete beginning node\n5)Delete last node\n6)Delete node of your desired position\n7)Traverse\n8)Search\n9)Exit\nYour choice:- ");
     scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
                int item;
                printf("Enter item you want to insert: ");
                scanf("%d",&item);
                insertAtFirst(item);
                break;
                }
            case 2:
                {
                int item;
                printf("Enter item you want to insert: ");
                scanf("%d",&item);
                insertAtLast(item);
                break;
                }
            case 3:
                {
                int item,position;
                printf("Enter item you want to insert: ");
                scanf("%d",&item);
                printf("Enter the position of node:- ");
                scanf("%d",&position);
                insertAt(position,item);
                break;
                }
            case 4:
                {
                deleteAtFirst();
                break;
                }
            case 5:
                {
                    deleteAtLast();
                    break;
                }
            case 6:
                {
                int position;
                printf("Enter position of node you want to delete: ");
                scanf("%d",&position);
                deleteAtPos(position);
                break;
                }
            case 7:
                {
                    traverse();
                    break;
                }
            case 8:
                {
                    int item;
                    printf("Enter item you want to search:- ");
                    scanf("%d",&item);
                    search(item);
                    break;
                }
            default:
                {
                    printf("Please Enter valid choice: ");
                }
};
}while(choice!=9);
return 0;
}
