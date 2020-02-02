#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  int n;
  scanf("%d",&n);
  int arr[n];
  for(int i = 0;i < n;i++)
  {
    scanf("%d",&arr[i]);
  }

  int max = 0;
  int *b = malloc(sizeof(char) * 256);
  int *c = malloc(sizeof(char) * 256);
  int i;
  for(i = 0;i < n;i++)
  {
    if(arr[i] > max) max = arr[i];
  }

  for(i = 0;i < max;i++)
  {
    c[i] = 0;
  }

  for(i = 0;i < n;i++)
  {
    c[arr[i]]++;
  }

  for(i = 1;i <= max;i++)
  {
    c[i] = c[i] + c[i - 1];
  }

  for(i = n - 1;i >= 0;i--)
  {
    b[--c[arr[i]]] = arr[i];
  }

  for(i = 0;i < n;i++)
  {
    printf("%d ",b[i]);
  }
  return 0;
}
