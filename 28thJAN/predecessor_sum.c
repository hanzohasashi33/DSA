#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i = 0;i < size;i++)
    {
        scanf("%d",&arr[i]);
    }
    int p[size+1];
    p[0]=0;
    for(int i=1;i<=size;i++)
        p[i]=p[i-1]+arr[i-1];
    int i=0,j;
    int max=0;
    for(int j=1;j<=size;j++)
    {
        if(p[j]-p[i]>max)
            max=p[j]-p[i];
        if(arr[i]>arr[j]) i=j;
    }
    printf("%d",max);
    return 0;    
}
