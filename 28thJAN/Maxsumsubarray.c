#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max(x,y) (x > y) ? x : y


int kadane(int arr[],int n)
{
  int msf = 0;
  int meh = 0;
  for(int i = 0;i < n;i++)
  {
    meh += arr[i];
    meh = max(meh,0);
    msf = max(msf,meh);
  }
  return msf;
}






int main()
{
  int arr[] = {1,2,3,4,5,6,-2,-4,4,-3,-2,-3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int maxsum = kadane(arr, n);
  printf("%d\n",maxsum);
  return 0;
}
