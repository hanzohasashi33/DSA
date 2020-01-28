#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void swap(int *a,int *b)
{
    int temp = * a;
    *a = *b;
    *b = temp;
}





void printarray(int arr[],int n)
{
    int i = 0;
    for(i = 0;i < n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}





void selectionsort(int arr[],int n)
{
    int i,j,min;
    for(i = 0;i < n - 1;i++)
    {
        min = i;
        for(j = i + 1;j < n;j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[min],&arr[i]);
        printarray(arr,n);
    }
}







int main()
{
    int n;
    scanf("%d",&n);
    int i;
    int arr[n];
    for(i = 0;i < n;i++)
    {
        scanf("%d",&arr[i]);
    }
    selectionsort(arr,n);
    printarray(arr,n);
    return 0;
}