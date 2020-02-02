//program to find max arr[j] - arr[i] in o(n)


#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  scanf("%d",&n);
  int arr[n];
  for(int i = 0;i < n;i++)
  {
    scanf("%d",&arr[i]);
  }
  
  int i,j,k;
  int max = -32627;


  for(i = 0;i < n;i++)
  {
    for(j = i;j < n;j++)
    {
      int sum = 0;
      for(k = i;k <= j;k++)
      {
        sum += arr[k];
      }
      if(sum > max)
      {
        max = sum;
      }
    }
  }

  printf("%d\n",max);
  return 0;
}
