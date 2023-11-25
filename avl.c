//Author:- Manish khadka 2023/01/08
//This code shows avl tree implementation in c

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tree{
int data;
tree* left;
tree* right;
}
typedef struct tree node;
node* root=NULL;

node* getNode(int data)
{
node* temp=(node*)malloc(sizeof(node));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;
}

int height(node* T)
{
int result=0,lh=0,rh=0;
if(T->left==NULL && T->right==NULL)	//having none
return 0;
else if(T->left!=NULL)		//go left
lh=1+height(T->left);
else						//go right
rh=1+height(T->right);
return((lh>rh)?lh:rh);
}
int BF(node* T)
{
int lh=0,rh=0;
if(T==NULL)
return 0;
if(t->left==NULL)
lh=0;
else
lh=1+height(T->left);
if(t->right==NULL)
rh=0;

}


void insert(node*,int data)
{
if(root==NULL)
{
root=getNode(data); 

}

