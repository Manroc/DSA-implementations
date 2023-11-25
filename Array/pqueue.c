//This program demonstrates the implementation of ascending priority queue

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 20
struct blueprint          //priority queue blueprint
{
int array[SIZE];
int front,rear;
};
typedef struct blueprint priority_queue;

priority_queue* createQueue()    //Function to create priority queue
{
	priority_queue *q;
q=(priority_queue*)malloc(sizeof(priority_queue));
q->front=q->rear=-1;
return q;
}

int isEmpty(priority_queue* q)   //Function to check empty status
{
if(q->front==-1 && q->rear==-1)
    return 1;
else
    return 0;
}

int isFull(priority_queue* q)           //Function to check Full status
{
if(q->rear==SIZE-1)
return 1;
else
    return 0;}
void enqueue(priority_queue* q,int item)     //Function for enqueue is special
{
if(isFull(q)){
    printf("Cannot enqueue");
}
else if(isEmpty(q)){
    q->front=q->rear=0;
    q->array[q->rear]=item;
  printf("Enqueue operation successful. Enqueued item is %d\n",q->array[q->rear]);
}
else{
        int i;
        i=q->rear;
        while( item < q->array[i] && i>=q->front)
        {
            q->array[i+1]=q->array[i];
            i--;
        }
        q->array[i+1]=item;
        q->rear++;
    printf("Enqueue operation successful. Enqueued item is %d\n",q->array[q->rear]);
    }
    }

void dequeue(priority_queue* q)    //Function for dequeue
{
    if(isEmpty(q))
    {
        printf("Nothing to dequeue. The queue is empty.\n");}
else if(q->front==q->rear)
{
int item;
item=q->array[q->front];
q->front=q->rear=-1;
printf ("Dequeued item is %d\n", item);}
        else {
                int item;
        item=q->array[q->front];
        q->front++;
        printf ("Dequeued item is %d\n", item);
    }}
void traverse (priority_queue* q) {
    printf ("Values in queue are:\n");
    for(int i=q->front;i<=q->rear;i++)
    printf("%d\t",q->array[i]);
    printf("\n");
    }
int main()     //Main() driver code
{
priority_queue *q;
q=createQueue();
enqueue(q,25);
enqueue(q,20);
traverse(q);
dequeue(q);
enqueue(q,1);
enqueue(q,2);
enqueue(q,33);
traverse(q);
return 0;
}
