//Merge Sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int arr[55];
void Merge(int arr[], int p, int q, int r){
    int i,j;
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1],R[n1+1];
    for(i=1;i<=n1;i++){
        L[i]=arr[p+i-1];
    }
    for(j=1;j<=n2;i++){
        R[j]=arr[j+q];
    }
    L[n1+1]=99;
    R[n2+1]=99;
    for(int k=p;k<=r;k++){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
    }
}
void merge_sort(int arr[], int p, int r){
    int q;
    if(p<r){
        q=(int)(p+r)/2;
        merge_sort(arr,p,q);
        merge_sort(arr,q+1,r);
        Merge(arr,p,q,r);
    }
}
void main()
{
	int i;
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
    merge_sort(arr,1,10);
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