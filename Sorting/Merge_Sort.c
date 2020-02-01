#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



void merge(int arr[],int low,int mid,int high)
{
  int temp[100000];
  int i = low;
  int j = mid + 1;
  int x = low;

  while(i <= mid && j <= high)
  {
    if(arr[i] <= arr[j])
    {
      temp[x++] = arr[i++];
    }
    else 
    {
      temp[x++] = arr[j++];
    }
  }
  while(i <= mid)
  {
    temp[x++] = arr[i++];
  }
  while(j <= high)
  {
    temp[x++] = arr[j++];
  }

  for(i = low;i <= high;i++)
  {
    arr[i] = temp[i];
  }
}





void mergesort(int arr[],int low,int high)
{
  if(low != high)
  {
    int mid = (low + high)/2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr,low,mid,high);
  }
}




int main()
{
  int n;
  scanf("%d",&n);
  int i = 0;
  int arr[n];
  for(i = 0;i < n;i++)
  {
    scanf("%d",&arr[i]);
  }
  mergesort(arr, 0, n - 1);
  for(i = 0;i < n;i++)
  {
    printf("%d ",arr[i]);
  }
  return 0;
}
