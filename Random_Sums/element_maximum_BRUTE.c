//Given an array of n numbers. Give an algorithm for finding the element which appears the maximum number of times in the array?

//BRUTE FORCE

#include <stdio.h>
#include <stdlib.h>


int main()
{
  int n;
  scanf("%d",&n);
  int arr[n];
  int i = 0;
  for(i = 0;i < n;i++)
  {
    scanf("%d",&arr[i]);
  }
  int counter = 0,max = 0;
  int j = 0;
  for(i = 0;i < n;i++)
  {
    counter = 1;
    for(j = i + 1;j < n;j++)
    {
      if(arr[i] == arr[j])
      {
        counter += 1;
      }
    }
    if(counter > max)
    {
      max = counter;
    }
  }
  printf("%d\n",max);
  return 0;
}
