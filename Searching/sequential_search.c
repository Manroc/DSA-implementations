#include<stdio.h>
#include<conio.h>
void LinearSearch(int a[],int size,int key)
{
int flag=0,i;
for(i=0;i<size;i++)
{
if(key==a[i])
{
flag=1;
printf("Search Successful. Your item is at index %d\n",i);
}
}
if(flag==0)
printf("Search Unsuccessful\n");
}

int main()
{
int key;
int a[10]={55,34,1,22,3,66,9953,0,42,8};
printf("Enter item you want to search in array:-\n");
scanf("%d",&key);
LinearSearch(a,10,key);
LinearSearch(a,10,66);
return 0;
}
