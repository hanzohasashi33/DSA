#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int tree[2 * N];



void build(int arr[],int n)
{
    for(int i = 0;i < n;i++)
    {
        tree[n + i - 1] = i;
    }

    for(int i = n - 2;i >= 0;i--)
    {
        if(arr[tree[2*i + 1]]  > arr[tree[2*i + 2]])
        {
            tree[i] = tree[2*i + 2];
        }    
        else 
        {
            tree[i] = tree[2*i + 1];
        }
    }
}




void printtree(int treearr[],int n)
{
    for(int i = 0;i < n;i++)
    {
        printf("%d ",treearr[i]);
    }
    printf("\n");
}




int lastmin(int arr[],int i,int n)
{
    int j = n - 1;
    while(arr[j] > arr[i])
    {
        j--;
    }
    return j;
}



int optimizedlastmin(int arr[],int i,int n)
{
    int p = 0;
    while(p < n - 1)
    {
        if(arr[tree[2*p + 2]] <= arr[i])
        {
            p = 2*p + 2;
        }
        else 
        {
            p = 2*p + 1;
        }
    }
    return tree[p];
}







int main()
{
    int arr[] = {4,8,9,6,24,32,28,27,30,50,1,4,3,12,18,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    build(arr,n);
    printtree(tree,2*n - 1);
    printf("%d ",lastmin(arr,4,n));
    printf("%d\n",optimizedlastmin(arr,4,n));
    return 0;
}
