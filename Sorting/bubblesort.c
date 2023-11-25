//Author:- Manish 2023/1/11
//Bubble sort
#include<stdio.h>
#include<conio.h>
int main()
{
	int temp,n=5;
int a[]={50,40,33,29,1};
printf("The unsorted array is:-\n");
for(int i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\n");
for(int i=0;i<n-1;i++)		//For pass
{
for(int j=0;j<n-1-i;j++)	//For comparing each element
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
printf("Sorted array is:-\n");
for(int i=0;i<n;i++)
printf("%d\t",a[i]);
return 0;
}
