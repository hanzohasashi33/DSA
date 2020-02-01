#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
  int n;
  scanf("%d",&n);
  int i,j;
  int arr[n];
  for(i = 0;i < n;i++)
  {
    scanf("%d",&arr[i]);
  }
  int k;
  int count = 0;
  scanf("%d",&k);
  for(i = 0;i < n -1;i++)
  {
    for(j = i + 1;j < n;j++)
    {
      if(arr[i] + arr[j] == k)
      {
        count ++;
        printf("%d %d\n",i,j);
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
