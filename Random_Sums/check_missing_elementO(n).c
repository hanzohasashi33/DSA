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
  int sum = ((n + 1)*(n + 2))/2;
  for(int i = 0;i < n;i++)
  {
    sum -= arr[i];
  }
  printf("%d\n",sum);
  return 0;
}
