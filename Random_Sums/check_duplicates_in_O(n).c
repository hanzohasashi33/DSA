//to check duplicates in order(n)

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
  int i;
  for(i = 0;i < n;i++)
  {
    if(arr[abs(arr[i])] < 0)
    {
      printf("Duplicates exist");
      break;
    }
    else 
    {
      arr[arr[i]] = -arr[arr[i]];
    }
  }
  if(i == n)
  {
    printf("No duplicates");
  }
  return 0;
}
