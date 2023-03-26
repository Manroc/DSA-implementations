//Array(static) implementation of a stack using C

#include<stdio.h>
#include<conio.h>
int stack[21],top=-1,choice=0,size,item;
int isFull(){
if(top==size-1)
    return 1;
else
    return 0;
};
int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
};
void push(int item){
if(isFull())
{
    printf("Stack is full cannot push.\n");
}
else
{
    top++;
    stack[top]=item;
    printf("%d is pushed sucessfully.\n",item);
}
};
void pop(){
if(isEmpty()){
    printf("Stack is empty. Cannot pop.\nExiting.");
}
else
{
    printf("Popped item is %d\n",stack[top]);
    top--;
}
};
void show(){
    if(isEmpty())
        printf("Stack is empty. Noting to show.\n");
    else{
    printf("Items in stack are:-\n");
for(int i=0;i<=top;i++){
    printf("%d\t",stack[i]);
}
    }
};

int main()
{
    printf("Enter your stack size[max size can be 20]: ");
    scanf("%d",&size);

    printf("*********Stack operations using array*********");

printf("\n----------------------------------------------\n");
    while(choice != 4)
    {
        printf("\nChose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("\n Enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter item you want to push: ");
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
                show();
                break;
            }
            case 4:
            {
                printf("Exiting....\n");
                break;
            }
            default:
            {
                printf("Please Enter valid choice: ");
            }
        }
    }
}
