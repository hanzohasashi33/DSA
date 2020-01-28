#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



void swap(int *a,int *b)          //swap function
{
    int temp = *a;
    *a = *b;
    *b = temp;
}



void printarray(int arr[],int n)          //function to print arrays
{
    int i;
    for(i = 0;i < n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}




void bubblesort(int arr[],int n)             //function to do bubblesort
{
    int i,j;
    for(i = 0;i < n - 1;i++)
    {
        for(j = 0;j < n- i - 1;j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j],&arr[j + 1]);
            }
        }
        printarray(arr,n);          //to see all iterations
    }
}







int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&arr[i]);
    }
    bubblesort(arr,n);
    printarray(arr,n);
    return 0;
}
