#include <bits/stdc++.h>
using namespace std;


const int N = 100000;
int tree[2 * N];




void build(int arr[],int n)
{
    for(int i = 0;i < n;i++)
    {
        tree[n + i - 1] = arr[i];
    }

    for(int i = n - 2;i >= 0;i--)
    {
        tree[i] = tree[2*i + 2] + tree[2*i + 1];
    }
}




void update(int p,int value,int n)
{
    tree[p + n] = value;
    p = p + n;

    for(int i = p;i > 1;i>>=1)
    {
        tree[i>>1] = tree[i] + tree[i^1];
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
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    build(arr,n);
    printtree(tree,2*n - 1);
    update(0,2,n);
    printtree(tree,2*n - 1);
    return 0;
}
