//program to find number of inversion pairs


#include <stdio.h>
#include <stdlib.h>


int main()
{
  int n;
  scanf("%d",&n);
  int arr[n];
  int i,j,count = 0;
  for(i = 0;i < n;i++)
  {
    scanf("%d",&arr[i]);
  }

  for(i = 0;i < n - 1;i++)
  {
    for(j =i + 1;j < n;j++)
    {
      if(arr[i] > arr[j])
      {
        count ++;
      }
    }
  }

  printf("%d\n",count);
  return 0;
}
