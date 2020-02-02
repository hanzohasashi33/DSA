#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main()
{
  int n;
  scanf("%d",&n);
  int arr[n];
  for(int i = 0;i < n;i++)
  {
    scanf("%d",&arr[i]);
  }
  int i,j;
  int min = 1000000;
  for(i = 0;i < n- 1;i++)
  {
    for(j = i + 1;j < n;j++)
    {
      if(abs(arr[i] - arr[j]) <= min)
      {
        min = abs(arr[i] - arr[j]);
      }
    }
  }
  printf("%d\n",min);
  return 0;
}
