#include <bits/stdc++.h>
using namespace std ;

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
        else tree[i] = tree[2*i + 1];

        i = (i-1)/2;
    }
}




int rangeminquery(int a[],int n,int i,int j,int start,int end,int root)
{
    if(start > j || end < i)              //no overlap
    {
        return n;
    }
    else if(start >= i && end <= j)       //complete overlap
    {
        return tree[root];
    }

    int mid = (start + end)/2;            //partial overlap
    int left = rangeminquery(a,n,i,j,start,mid,2*root+1);
    int right = rangeminquery(a,n,i,j,mid+1,end,2*root+2);

    if(a[left] < a[right])
    {
        return left;
    }
    else return right;
}





void build(int arr[],int n)
{
    for(int i = 0;i < n;i++)
    {
        tree[n + i - 1] = i;
    }

    for(int i = n - 2;i >= 0;i--)
    {
        if(arr[tree[2*i+1]]>arr[tree[2*i+2]])
        {
            tree[i] = tree[2*i+2];
        }
        else tree[i] = tree[2*i+1];
    }
}






void printtree(int treearr[],int n)
{
    for(int i = 0;i < n;i++)
    {
        cout << treearr[i] << " ";
    }
    cout << '\n';
}



int main()
{
    int a[] = {4,1,3,2,8,12,14,16};
    int n = sizeof(a)/sizeof(a[0]);
    build(a,n);
    printtree(tree,2*n -1);
    update(a,7,13,n);
    printtree(tree,2*n - 1);
    cout << "Rangeminquery of interval [4,6] is " << rangeminquery(a,n,4,6,0,n-1,0) << endl;
    return 0;
}
