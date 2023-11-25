#include<stdio.h>

#include<conio.h>

#include<stdlib.h>

struct BST {
        int data;
        struct BST * leftchild;
        struct BST * rightchild;
};
typedef struct BST node;

node * root;
node * newnode;



node * getNode(int data) {
        newnode = (node * ) malloc(sizeof(node));
        newnode -> data = data;
        newnode -> leftchild = NULL;
        newnode -> rightchild = NULL;
        return newnode;
}

/*void insert(node * temp, int data) {
        newnode = getNode(data);
        if (temp == NULL) {
                root = newnode;
        } else if (data < temp -> data) {
                if (temp -> leftchild == NULL) {
                        temp -> leftchild = newnode;
                } else {
                        insert(temp -> leftchild, data);
                }
        } else if (data > temp -> data) {
                if (temp -> rightchild == NULL) {
                        temp -> rightchild = newnode;
                } else {
                        insert(temp -> rightchild, data);
                }
        } else {
                printf("\nCannot insert duplicate value\n");
        }
}*/

void insert(node * temp,int data) {
        newnode = getNode(data);
        if (temp == NULL) {
                root = newnode;
        } else if (data < temp -> data) {
                if (temp -> leftchild == NULL) {
                        temp -> leftchild = newnode;
                } else {
                        insert(temp -> leftchild, data);
                }
        } else if (data > temp -> data) {
                if (temp -> rightchild == NULL) {
                        temp -> rightchild = newnode;
                } else {
                        insert(temp -> rightchild, data);
                }
        } else {
                printf("\nCannot insert duplicate value\n");
        }
}

node* insertRoot(int data)
{
	root=getNode(data);
	return root;
}

node * findMin(node * temp) {
        node * min;
        if (temp -> leftchild == NULL)
                min = temp;
        else {
                min = findMin(temp -> leftchild);
        }
        return min;
}

node * search(node * temp, int key) {
        node * found;
        if (temp == NULL) {
                printf("\nThe tree is empty\n");
                return NULL;
        } else if (temp -> data == key) {
                return temp;
        } else if (temp -> data < key) {
                found = search(temp -> rightchild, key);
                return found;
        } else if (temp -> data > key) {
                found = search(temp -> leftchild, key);
                return found;
        } else {
                printf("\nNot found\n");
                return NULL;
        }
}



void printInorder(node* root)
{
	if(root==NULL)
	return;
	printInorder(root->leftchild);
	printf("%d\t",root->data);
	printInorder(root->rightchild);
}

node* delete(node* root,int data)
{
	if(root==NULL)
	return root;
	else if (data < root->data)
	root->leftchild=delete(root->leftchild,data);
	else if (data> root->data)
	root->rightchild=delete(root->rightchild,data);
	else      //Got you!!! now i will delete u
	{
		if(root->leftchild==NULL && root->rightchild==NULL) //no child case
		{
			node* temp = root;
			free(temp);
			root=NULL;
		}
		else if(root->leftchild==NULL) 			//node with rightchild case
		{
			node* temp=root;
			root=root->rightchild;
			free(temp);
		}
		else if(root->rightchild==NULL)			//node with leftchild case	
		{
			node* temp=root;
			root=root->leftchild;
			free(temp);
		}
		else                				 //Two child case
		{
			node* temp=findMin(root->rightchild);
			root->data=temp->data;
			root->rightchild=delete(root->rightchild,root->data);
		}
		
	}	
	return root;		
	}

node* findMax(node* root)
{
	if(root->rightchild==NULL)
	return root;
	else
		{
			node* temp;
			temp=findMax(root->rightchild);
			return temp;
		}
}

void printPreorder(node* root)
{
	if(root==NULL)
	return;
	printf("%d\t",root->data);
	printPreorder(root->leftchild);
	printPreorder(root->rightchild);
}
void printPostorder(node* root)
{
	if(root==NULL)
	return;
	printPostorder(root->leftchild);
	printPostorder(root->rightchild);
	printf("%d\t",root->data);
}

/*int main() {
        printf("Start of the program\n");
        root = getNode(50);
        printf("\nRoot conatains %d\n", root -> data);
        insert(root, 60);
        insert(root, 40);
        insert(root, 70);
        insert(root,44);
        insert(root,-3);
        insert(root,-555);
        insert(root,555);
        insert(root, 30);
        insert(root, 80);
        insert(root, 20);
           printf("PREORDER:-\n");
           printPreorder(root);
              printf("POSTORDER:-\n");
              printPostorder(root);
        printf("INORDER:-\n");
        printInorder(root);
        printf("\n");
        delete(root,70);
           printf("INORDER:-\n");
        printInorder(root);
        printf("\n");
        delete(root,50);
           printf("INORDER:-\n");
        printInorder(root);
        node* found=findMax(root);
        printf("\nThe max data in tree is %d\n",found->data);
        return 0;
}*/
int height(node* T)
{
if(T==NULL)
return -1;
int lh,rh;
lh=height(T->leftchild);
rh=height(T->rightchild);
int result=(lh>rh)?lh:rh;
return(result+1);
}	
int main()
{
	int choice=0;
	do{

		printf("\n1)Insert as Root\n2)Insert\n3)Delete\n4)Pre-order traversal\n5)Inorder Traversal\n6)Post order Traversal\n7)Find Min\n8)Find max\n9)Find height\n10)Exit\nYour Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				int item;
				printf("Enter item :");
				scanf("%d",&item);
				root=insertRoot(item);
				break;
			}
			case 2:
			{
				int item;
				printf("Enter item :");
				scanf("%d",&item);
				insert(root,item);
				break;
			}
			case 3:
			{
				int item;
				printf("Enter item you want to delete:");
				scanf("%d",&item);
				delete(root,item);
				break;
			}
			case 4:
			{
				printPreorder(root);
				break;
			}
			case 5:
			{
				printInorder(root);
				break;
			}
			case 6:
			{
				printPostorder(root);
				break;
			}
			case 7:
			{
				node* min;
				min=findMin(root);
				printf("Minimum data in tree is %d\n",min->data);
				break;
			}
			case 8:
			{
				node* max;
				max=findMax(root);
				printf("Maximum data in tree is %d\n",max->data);
				break;
			}
			case 9:
			{
				int h;
				h=height(root);
				printf("Height of tree is %d\n",h);
				break;
			}
			case 10:
			{
				printf("Exiting\n");
				break;
			}
			default:
			{
				printf("INVALID CHOICE");
				break;
			}		
	}
}while(choice!=10);
return 0;
}
