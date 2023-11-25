//Author: Manish Khadka 2023/01/11
//Insertion sort

#include<stdio.h>
#include<conio.h>
int main()
{
int a[5]={44,2,55,23,1};
int i,j,n=5,temp;
printf("The unsorted array is:-\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\n");
//Insertion sort
for(i=1;i<n;i++)
{
temp=a[i];
j=i-1;
while(j>=0 && a[j]>temp)
{
a[j+1]=a[j];
j--;
}		//end of while loop
a[j+1]=temp;
}		//end of outer for loop
printf("Sorted array using insertion sort is:-\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
return 0;
}
