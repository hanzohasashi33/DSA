#include <stdio.h>
#include <stdlib.h>


void binary(int n,char arr[])
{
  if(n < 1)
  {
    printf("%s\n",arr);
  }
  else 
  {
    arr[n - 1] = '0';
    binary(n - 1,arr);
    arr[n - 1] = '1';
    binary(n - 1,arr);
  }
}





int main()
{
  int n;
  scanf("%d",&n);
  char arr[n];
  binary(n, arr);
  return 0;
}
