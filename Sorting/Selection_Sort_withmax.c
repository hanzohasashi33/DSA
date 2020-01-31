#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  scanf("%d",&n);
  int i,j;
  int max = 0;
  int arr[n];
  for(i = 0;i < n;i++)
  {
    scanf("%d",&arr[i]);
  }

  for(i = 0;i < n - 1;i++)
  {
    max = 0;
    for(j = 0;j < n - i - 1;j++)
    {
      if(arr[j] > arr[max])
      {
        max = j;
      }
    }
    if (arr[j] < arr[max])
    {
      int temp = arr[j];
      arr[j] = arr[max];
      arr[max] = temp;
    }
  }

  for(i = 0;i < n;i++)
  {
    printf("%d ",arr[i]);
  }
  return 0;
}
