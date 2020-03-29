#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) {int temp;temp = a;a = b;b = temp;}



void topdownheapify(int heap[],int length,int parent)
{
    int rightchild = 2*parent + 2;
    int leftchild = 2*parent + 1;

    while(rightchild < length)
    {
        int maxchild;
        if(heap[leftchild] < heap[rightchild])
        {
            maxchild = rightchild;
        }
        else maxchild = leftchild;


        if(heap[parent] > heap[maxchild])
        {
            swap(heap[parent],heap[maxchild]);
            parent = maxchild;
            rightchild = 2 * parent + 2;
            leftchild = 2 * parent + 1;
        }
        else break;
    }


    if(leftchild < length && heap[parent] > heap[leftchild])
    {
        swap(heap[parent],heap[leftchild]);
    }
}










void buildheap(int heap[],int length)
{
    for(int i = length/2;i >= 0;i--)
    {
        topdownheapify(heap,length,i);
    }
}









int main()
{
    int n;
    cin >> n;
    int * heap = (int *)malloc(sizeof(int) * n);

    for(int i = 0;i < n;i++) cin >> heap[i];

    buildheap(heap,n);

    for(int i = 0;i < n;i++) cout << heap[i] << " ";
    cout << endl;
    return 0;
}
