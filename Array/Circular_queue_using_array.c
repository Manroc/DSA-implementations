//C program that implements circular queue data structure using Array(static)
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 5
struct blueprint          //circular_queue blueprint
{
int array[SIZE];
int front,rear;
};
typedef struct blueprint circular_queue;

circular_queue* createQueue()    //Function to create circular_queue
{
	circular_queue *q;
q=(circular_queue*)malloc(sizeof(circular_queue));
q->front=q->rear=-1;
return q;
}

int isEmpty(circular_queue* q)   //Function to check empty status
{
if(q->front==-1 && q->rear==-1)
    return 1;
else
    return 0;
}

int isFull(circular_queue* q)           //Function to check Full status
{
if((q->rear+1)%SIZE==q->front)
return 1;
else
return 0;
}
void enqueue(circular_queue* q,int item)     //Function for enqueue
{
if(isFull(q))
{
    printf("Cannot enqueue, The Circular queue is full.\n");
}
else if(isEmpty(q)){
    q->front=q->rear=0;
    q->array[q->rear]=item;
    printf("Enqueue operation sucessful. Enqueued item is %d\n",q->array[q->rear]);
}
else{
    q->rear=(q->rear+1)%SIZE;
    q->array[q->rear]=item;
    printf("Enqueue operation sucessful. Enqueued item is %d\n",q->array[q->rear]);
}
}

void dequeue(circular_queue* q)    //Function for dequeue
{
    if(isEmpty(q))
    {
        printf("Nothing to decircular_queue. The circular_queue is empty.\n");
    }
    else if(q->front==q->rear)
    {
        int item;
        item=q->array[q->front];
        q->front=q->rear=-1;
        printf("Dequeued item is %d\n",item);
    }
        else{
        int item;
        item=q->array[q->front];
       q->front=(q->front+1)%SIZE;
        printf("Dequeued item is %d\n",item);
    }
}




void traverse(circular_queue* q)         //Function that displays values in circular_queue
{
    int i;
    printf("Values in circular_queue are:\n");
    for(i=q->front;i!=q->rear;i=(i+1)%SIZE)
    printf("%d\t",q->array[i]);
    printf("%d",q->array[i]);
    printf("\n");
    }

int main()     //Main() driver code
{
int choice=0;
circular_queue *q;
q=createQueue();
do{
    printf("1)Enqueue\n2)Dequeue\n3)Traverse\n4)Exit\nYour choice:- ");
    scanf("%d",&choice);
    switch(choice){

    case 1:
            {
                int item;
                printf("Enter item you want to Enqueue: ");
                scanf("%d",&item);
                enqueue(q,item);
                break;
            }
            case 2:
            {
                dequeue(q);
                break;
            }
            case 3:
            {
                traverse(q);
                break;
            }
            case 4:
            {
                printf("Exiting....");
                break;
            }
            default:
            {
                printf("Please Enter valid choice: ");
            }

    }
}while(choice!=4);
return 0;
}
