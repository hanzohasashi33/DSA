#include <bits/stdc++.h>
using namespace std ;



void bottomupheapify(int heap[],int child)
{
    int parent = (child - 1)/2;
    while(parent >= 0 && heap[parent] > heap[child])
    {
        swap(heap[parent],heap[child]);
        child = parent;
        parent = (child - 1)/2;
    }
}






void add(int heap[],int length,int data)
{
    heap[length++] = data;
    bottomupheapify(heap,length - 1);
}







int main()
{
    int n;
    cin >> n;
    int * heap = (int *)malloc(sizeof(int) * (n+1));

    int length = 0;
    for(int i = 0;i < n;i++)
    {
        int data;
        cin >> data;
        add(heap,length,data);
        length++;
    }

    for(int i = 0;i < length;i++)
    {
        cout << heap[i];
    } 
    cout << endl;
    return 0;
}
