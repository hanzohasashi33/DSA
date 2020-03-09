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






int main()
{
    int a[] = {4,1,3,2,8,12,14,16};
    int n = sizeof(a)/sizeof(a[0]);
    build(a,n);
    printtree(tree,2 * n - 1);
    return 0;
}
