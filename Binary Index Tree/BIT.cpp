#include <iostream>
using namespace std;




int getsum(int bittree[],int index)
{
    int sum = 0;
    index ++;
    while(index > 0)
    {
        sum += bittree[index];
        index -= index & (-index);
    }
    return sum;
}





void updateBIT(int bittree[],int n,int index,int val)
{
    index += 1;
    while(index <= n)
    {
        bittree[index] += val;
        index += index & (-index);
    }
}









int * constructbittree(int arr[],int n)
{
    int * bittree = new int[n + 1];
    for(int i = 1;i <= n;i++)
    {
        bittree[i] = 0;
    }

    for(int i = 0;i < n;i++)
    {
        updateBIT(bittree,n,i,arr[i]);
    }
    return bittree;
}





int main()
{
    int arr[] = {0,4,3,2,-1,-2,6,-3,7,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *bittree = constructbittree(arr,n);
    cout << getsum(bittree,5);
    return 0;
}
