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

int level(char symbol){
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
	};
int isOperator(char check);

void infixtopostfix(char *ptr)
{
static int indexorgi=0;
static int indexoperator=0;
static int indexfinal=0;
int flag=0;
while(*(ptr+indexorgi)!='\0')
{
if(isOperator(*(ptr+indexorgi)))
{
    if(topoperator==-1)
    {
     pushOperator(*(ptr+indexorgi));
     indexorgi++;
     test++;
     printf("step=%d  stack=%s\t  final =%s\n",test,operator,final);
     continue;
    }
    if(isBracket(*(ptr+indexorgi)))
    {

        int temp;
        temp=(int)(*(ptr+indexorgi));

        test++;
        if(temp==40)
        {
            pushOperator(*(ptr+indexorgi));
            indexorgi++;
            test++;
     printf("step=%d  stack=%s\t  final =%s\n",test,operator,final);
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
     printf("step=%d  stack=%s\t  final =%s\n",test,operator,final);
            temp=(int)operator[topoperator];
            if(temp==40)
            {
                char cache=popOperator();
            }
            }
            indexorgi++;
            if(*(ptr+indexorgi)=='\0')
            atLast();
            continue;
        }
    }
    if(level(*(ptr+indexorgi))>level(operator[topoperator]))
    {
        pushOperator(*(ptr+indexorgi));
        indexorgi++;
        if(*(ptr+indexorgi)=='\0')
            atLast();
            test++;
     printf("step=%d  stack=%s\t  final =%s\n",test,operator,final);
        continue;
    }
        else
        {
            while(level(*(ptr+indexorgi))<=operator[topoperator])
            {
                 char transfer;
                 transfer=popOperator();
                 pushFinal(transfer);
            }
            pushOperator(*(ptr+indexorgi));
            indexorgi++;
            if(*(ptr+indexorgi)=='\0')
            atLast();
            test++;
    printf("step=%d  stack=%s\t  final =%s\n",test,operator,final);
            continue;
        }
}
else
{
    pushFinal(*(ptr+indexorgi));
    indexorgi++;
    if(*(ptr+indexorgi)=='\0')
            atLast();
            test++;
    printf("step=%d  stack=%s\t  final =%s\n",test,operator,final);
    continue;
}
}
}
    /*pushFinal(*(ptr+indexorgi));
    indexorgi++;
    break;*/

/*else
{
    if(topoperator==-1 || level(*ptr+indexorgi)>level(operator[topoperator]))
    {
        pushOperator(*(ptr+indexoperator));
        indexoperator++;
        break;
    }
    if(level(*(ptr+indexorgi)<level(operator[topoperator])))
    {
        char temp;
        temp=popOperator();
        pushFinal(temp);
        indexoperator--;
        indexfinal++;
        break;
    }
}
if(flag==1)
{
    while(indexoperator!=-1)
    {
        char temp;
        temp=popOperator();
        pushFinal(temp);
        indexoperator--;
    }
}
if(*(ptr+indexorgi)=='\0')
    flag=1;
}

}*/
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
    
    int main()                     //DRIVER CODE
{
printf("Enter infix experssion: ");
gets(original);
infixtopostfix(original);
 printf("Final postfix expression is :- %s",final);
 return 0;
}
