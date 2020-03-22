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
        if(arr[tree[2*i + 1]] > arr[tree[2*i + 2]])
        {
            tree[i] = tree[2*i + 2];
        }
        else 
        {
            tree[i] = tree[2*i + 1];
        }
    }
}






int nextrightmin(int arr[],int i,int n)
{
    int j = i + 1;
    while(j < n && arr[j] >= arr[i])
    {
        j++;
    }
    return j;
}


int optnextrightmin(int arr[],int i,int n)
{
    int p = 0,s = 0,e = n - 1,j = n;
    while(p < n - 1)
    {
        int mid = (s + e)/2;
        if(i <= mid)
        {
            if(arr[tree[2*p + 2]] < arr[i]) j = 2*p + 2;
            p = 2*p + 1;
            e = mid;
        }
        else 
        {
            p = 2*p + 2;
            s = mid + 1;
        }
    }

    while(j < n - 1)
    {
        if(arr[tree[2*j + 1]] < arr[i])
        {
            j = 2*j + 1;
        }
        else 
        {
            j = 2*j + 2;
        }
    }
    return j;
}




void printtree(int arr[],int n)
{
    for(int i = 0;i < n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    int a[] = {12,3,443,4543,323,4554,5432,32532,6,67,886,87};
    int n = sizeof(a)/sizeof(a[0]);
    build(a,n);
    printtree(tree,2*n - 1);
    cout << nextrightmin(a,2,n) << endl;
    cout << optnextrightmin(a,2,n) << endl;
    return 0;
}
