#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void swap(int *a,int *b)
{
    int temp = *a;
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



void insertionsort(int arr[],int n)
{
    int i,key,j;
    for(i = 1;i < n;i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printarray(arr,n);
    }    
}






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
    insertionsort(arr,n);
    printarray(arr,n);
    return 0;
}
