#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int tree[2 * N];






void update(int arr[],int i,int x,int n)
{
  arr[i] = x;
  i = (n + i - 2)/2;
  while(i > 0)
  {
    if(arr[tree[2*i + 1]] > arr[tree[2*i + 2]])
    {
      tree[i] = tree[2*i + 2];
    }
    else 
    {
      tree[i] = tree[2*i + 1];
    }
    i = (i - 1)/2;
  }
}




int ReturnMinQuery(int A[], int n, int i, int j, int start, int end, int root)
{    
    if (start > j || end < i)
    {
        return n;
    }
    else if (start >= i && end <= j)
    {
        return tree[root];
    }

    int mid = (start+end)/2;

    int left = ReturnMinQuery(A,n,i,j,start,mid,2*root+1);
    int right = ReturnMinQuery(A,n,i,j,mid+1,end,2*root+2);

    if(A[left] < A[right])
        return left;
    else
        return right;
}



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
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&arr[i]);
    }
    arr[n] = INT_MAX;
    build(arr,n);
    printtree(tree,2*n-1);
    update(arr,1,1,n);
    update(arr,6,14,n);
    printtree(tree,2*n-1);
    int index = ReturnMinQuery(arr,n,1,5,0,n-1,0); //Update range according to given query
    printf("Minimum value in given range (1,5) is %d\n",index);

    return 0;
}
