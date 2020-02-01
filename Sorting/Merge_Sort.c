#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>




void merge(int arr[],int l,int k,int r)
{
  int b[10000];
  int i = l;
  int j = k + 1;
  int x = l;
  while(i <= k && j <= r)
  {
    if(arr[i] <= arr[j])
    {
      b[x++] = arr[i++];
    }
    else 
    {
      b[x++] = arr[j++];
    }
  }
  while(i <= k)
  {
    b[x++] = arr[i++];
  }
  while(j <= r)
  {
    b[x++] = arr[j++];
  }
  for(i = l;i <= r;i++)
  {
    arr[i] = b[i];
  }
}





void mergesort(int arr[],int l,int r)
{
  if(l != r)
  {
    int k = (l + r)/2;
    mergesort(arr, l, k);
    mergesort(arr,k+1,r);
    merge(arr,l,k,r);
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
