//Author: Manish Khadka 2023/01/11
//Selection sort

#include<stdio.h>
#include<conio.h>
int main()
{
int a[5]={44,2,55,23,1};
int imin,temp,n=5,i,j;
printf("The unsorted array is:-\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\n");
//Selection sort
for(i=0;i<n-1;i++)		//start of first loop
{
	
	imin=i;
for(j=i+1;j<n;j++)		//start of second loop
{

if(a[j]<a[imin])
{
imin=j;
}
}	//end of second loop
temp=a[i];
a[i]=a[imin];
a[imin]=temp;
} //end of first loop
printf("Sorted array using selection sort is:-\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
return 0;
}
