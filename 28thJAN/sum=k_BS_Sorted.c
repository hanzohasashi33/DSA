#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//FOR SORTED ARRAY


int binary_search(int arr[],int l,int r,int k)
{
  while(l <= r)
  {
    if(arr[l] + arr[r] == k) return 1;
    else if(arr[l] + arr[r] > k) r--;
    else l++;
  }
  return -1;
}





int main()
{
  int n;
  scanf("%d",&n);
  int arr[n];
  int i,j;
  for(i = 0;i < n;i++)
  {
    scanf("%d",&arr[i]);
  }
  int k;
  scanf("%d",&k);
  int boolean = binary_search(arr,0, n - 1,k);
  printf("%d",boolean);
  return 0;
}
