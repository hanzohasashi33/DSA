#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void swap(int *a,int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}




int partition(int arr[],int i,int j,int pivot)
{
    int l=i;
    int r=j;
    while(l<=r)
    {
        while(l<=r && arr[l]<=pivot) 
            l++;
        while(l<=r && arr[r]>pivot) 
            r--;
        if(l<=r) 
        {
            swap(&arr[l],&arr[r]);
            l++; r--;
        }
    }
    int k = l-1;
    swap(&arr[i-1],&arr[k]);
    arr[k] = pivot;
    return k;
}




void Rquicksort(int arr[],int i,int j)
{
    if(i<j)
    {
        int pivot_index=rand()%(j-i+1)+i;
        swap(&arr[i],&arr[pivot_index]);
        int k=partition(arr,i+1,j,arr[i]);
        Rquicksort(arr,i,k-1);
        Rquicksort(arr,k+1,j);
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
  Rquicksort(arr, 0, n - 1);
  int min = 1000000;
  int i;
  for(i = 1;i < n;i++)
  {
    if(arr[i] - arr[i - 1] < min)
    {
      min = arr[i] - arr[i - 1];
    }
  }
  printf("%d",min);
  return 0;
}
