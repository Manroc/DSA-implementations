#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int count = 0;

// Creating a stack
struct stack {
  char items[MAX];
  int top;
};
typedef struct stack st;

void createEmptyStack(st *s) {
  s->top = -1;
}

// Check if the stack is full
int isfull(st *s) {
  if (s->top == MAX - 1)
    return 1;
  else
    return 0;
}

// Check if the stack is empty
int isempty(st *s) {
  if (s->top == -1)
    return 1;
  else
    return 0;
}

// Add elements into stack
void push(st *s, int newitem) {
  if (isfull(s)) {
    printf("STACK FULL");
  } else {
    s->top++;
    s->items[s->top] = newitem;
  }
  count++;
}

// Remove element from stack
void pop(st *s) {
  if (isempty(s)) {
    printf("\n STACK EMPTY \n");
  } else {
    printf("Item popped= %c", s->items[s->top]);
    s->top--;
  }
  count--;
  printf("\n");
}

// Print elements of stack
void printStack(st *s) {
  printf("Stack: ");
  for (int i = 0; i < count; i++) {
    printf("%c ", s->items[i]);
  }
  printf("\n");
}

// Driver code
int main() {

  st *Experssion,*operatorstack,*postfix;
  Expression = (*st)malloc(sizeof(st));
  createEmptyStack(s);
  push(s, A);
  push(s, +);
  push(s, B);
  push(s, *);
  push(s, C);
  printStack(s);

  pop(s);

  printf("\nAfter popping out\n");
  printStack(s);
}
