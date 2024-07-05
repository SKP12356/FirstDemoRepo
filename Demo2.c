//RANDOMIZED QUICK SORT
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void randomized_quickSort(int arr[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=randomized_partition(arr,p,r);
		randomized_quickSort(arr,p,q-1);
		randomized_quickSort(arr,q+1,r);
	}
}
int randomized_partition(int arr[],int p,int r)
{
	int i,temp;
	//to select a random element between index p and index r
	i=p+rand()%(r-p+1);
	//i=rand()%(r-p);
	temp=arr[i];
	arr[i]=arr[r];
	arr[r]=temp;
	return partition(arr,p,r);
}
int partition(int arr[],int p,int r)
{
	int x,i,j,temp1,temp2;
	x=arr[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(arr[j]<=x)
		{
			i=i+1;
			temp1=arr[i];
			arr[i]=arr[j];
			arr[j]=temp1;
		}
	}
	temp2=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp2;
	return (i+1);
}
void main()
{
	int arr[55],i;
	double total_time_taken;
	clock_t Start,end;
	for(i=1;i<=10;i++)
	{
		arr[i]=rand()%50;
	}
	printf("Array before sorting\n");
        for(i=1;i<=10;i++)
        {
                printf("%d ",arr[i]);
        }
	Start=clock();
	randomized_quickSort(arr,1,10);
	end=clock();
	total_time_taken=((double)(end-Start))/CLOCKS_PER_SEC;
	printf("Total time taken= %f\n",total_time_taken);
	printf("Array after sorting\n");
	for(i=1;i<=10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}