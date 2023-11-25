//Program to convert infix to postfix using stack
#include<stdio.h>
#include<conio.h>
#define MAX 30
char original[MAX],final[MAX],operator[MAX];
int topfinal=-1,topoperator=-1;
void atLast();
static int test=0;
int isBracket(char check);

void pushFinal(char a)
{
    topfinal++;
    final[topfinal]=a;
}
char popFinal()
{
    char a;
    a=final[topfinal];
    topfinal--;
    return a;
}
void pushOperator(char a)
{
    topoperator++;
    operator[topoperator]=a;
}
char popOperator()
{
    char a;
    a=operator[topoperator];
    topoperator--;
    return a;
}

void infixtopostfix(char orginal[]);
int level(char symbol);
int isOperator(char check);
void main()                             //DRIVER CODE
{
printf("Enter infix experssion: ");
gets(original);
infixtopostfix(original);
 printf("Final postfix expression is :- %s",final);
 getch();
}
void infixtopostfix(char original[])
{
int indexorgi=0;
int flag=0;
while((original[indexorgi])!='\0')
{
if(isOperator(original[indexorgi]))
{
    if(topoperator==-1)
    {
     pushOperator(original[indexorgi]);
     indexorgi++;
     test++;
     printf("step=%d        stack=%s        final =%s\n",test,operator,final);
     continue;
    }
    if(isBracket(original[indexorgi]))
    {

        int temp;
        temp=(int)(original[indexorgi]);

        test++;
        if(temp==40)
        {
            pushOperator(original[indexorgi]);
            indexorgi++;
            test++;
     printf("step=%d        stack=%s        final =%s\n",test,operator,final);
            continue;
        }
        else
        {
            while(temp!=40)
            {
            char transfer;
            transfer=popOperator();
            pushFinal(transfer);
             test++;
     printf("step=%d        stack=%s    final =%s\n",test,operator,final);
            temp=(int)operator[topoperator];
            if(temp==40)
            {
                char cache=popOperator();
            }
            }
            indexorgi++;
            if(original[indexorgi]=='\0')
            atLast();
            continue;
        }
    }
    if(level(original[indexorgi])>level(operator[topoperator]))
    {
        pushOperator(original[indexorgi]);
        indexorgi++;
        if(original[indexorgi]=='\0')
            atLast();
            test++;
     printf("step=%d        stack=%s        final =%s\n",test,operator,final);
        continue;
    }
        else
        {
            while(level(original[indexorgi])<=operator[topoperator])
            {
                 char transfer;
                 transfer=popOperator();
                 pushFinal(transfer);
            }
            pushOperator(original[indexorgi]);
            indexorgi++;
            if(original[indexorgi]=='\0')
            atLast();
            test++;
    printf("step=%d       stack=%s       final =%s\n",test,operator,final);
            continue;
        }
}
else
{
    pushFinal(original[indexorgi]);
    indexorgi++;
    if(original[indexorgi]=='\0')
            atLast();
            test++;
    printf("step=%d         stack=%s     final =%s\n",test,operator,final);
    continue;
}
}
}

int level(char symbol)
{
if(symbol=='^')
    return 4;
if(symbol=='/' || symbol=='*')
return 3;
if(symbol=='+'||symbol=='-')
return 2;
if(symbol=='(')
    return 1;
}
int isOperator(char check)
{
    if(check=='*' || check=='/' || check=='+' || check=='-' || check=='^' || check=='(' || check==')' || check=='{' || check=='}' || check=='[' || check==']')
        return 1;
    else
        return 0;
}
void atLast()
{
        while(topoperator!=-1)
    {
        char temp;
        temp=popOperator();
        pushFinal(temp);
    }
}

int isBracket(char check)
{
    int temp,bracketalert=0;
    temp=(int)check;
    if(temp==40 || temp==41){
        bracketalert=1;
        return bracketalert;
    }
    else
        return bracketalert;
    }
