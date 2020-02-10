#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(int * a,int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}



int partition(int arr[],int i,int j,int pivot)
{
    int l = i;
    int r = j;
    while(l <= r)
    {
        while((l <= r) && arr[l] <= pivot)
        {
            l++;
        }
        while(l <= r && arr[r] > pivot)
        {
            r--;
        }
        if(l <= r)
        {
            swap(&arr[l],&arr[r]);
            l++;
            r--;
        }
    }
    int k = l - 1;
    swap(&arr[i - 1],&arr[k]);
    arr[k] = pivot;
    return k;
}






int RFindRank(int arr[],int i,int j,int r)
{
    if(i < j)
    {
        int p = rand()%(j - i + 1) + i;
        swap(&arr[p],&arr[i]);
        int k = partition(arr,i + 1,j,arr[i]);
        if(r == j - k + 1)
        {
            return k;
        }
        else if(r < j - k + 1)
        {
            RFindRank(arr,k + 1,j,r);
        }
        else 
        {
            RFindRank(arr,i,k - 1,r - (j - k + 1));
        }
    }
}








int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int r;
    scanf("%d",&r);
    int index = RFindRank(arr,0,n - 1,r);
    printf("%d",arr[index]);
    return 0;
}
