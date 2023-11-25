//Author :- manish khadka 2023/01/12
//Quick sort   
//YO future manish do revise it past manish struggled hard understanding it
#include<stdio.h>
#include<conio.h>
void quickSort(int a[],int start,int end);
int partition(int a[],int start,int end);
int main()
{
int a[5]={44,85,74,1,96};
int i;
printf("Unsorted array is:-\n");
for(i=0;i<5;i++)
printf("%d\t",a[i]);
printf("\n");
quickSort(a,0,4);
printf("Sorted array using quick sort is:-\n");
for(int i=0;i<5;i++)
printf("%d\t",a[i]);
printf("\n");

}

int partition(int a[],int start,int end)		//partition function	
{
	int temp;
	int pindex=start;
	int pivot=a[end];
	for(int i=start;i<5;i++)
	{
		if(a[i]<pivot)
		{
			temp=a[i];				//swap(a[pindex],a[i]);
			a[i]=a[pindex];
			a[pindex]=temp;
			pindex++;
		}
	}
	temp=a[pindex];						//swap(a[pindex],a[end]);
	a[pindex]=a[end];
	a[end]=temp;
	return pindex;
		}

void quickSort(int a[],int start,int end)
{
if(start<end)
{
int p=partition(a,start,end);				//it will place my pivot in right order
quickSort(a,start,(p-1));						//it will place my left-sub array in order
quickSort(a,(p+1),end);							//it will place my right sub array in order
}
}

