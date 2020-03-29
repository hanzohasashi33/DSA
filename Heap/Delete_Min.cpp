#include <bits/stdc++.h>
#define swap(a,b) {int temp;temp = a;a= b;b = temp;}
using namespace std;



void bottomupheapify(int heap[],int child)
{
    int parent = (child - 1)/2;

    while(parent >= 0 && heap[parent] > heap[child])
    {
        swap(heap[child],heap[parent]);
        child = parent;
        parent = (child - 1)/2;
    }
}



void add(int heap[],int length,int data)
{
    heap[length++] = data;
    bottomupheapify(heap,length - 1);
}



void TopDownHeapify(int heap[], int length, int parent)
{
    int right_child = 2*parent + 2;
    int left_child = 2*parent + 1;
    while(right_child < length)
    {
        int max_child;
        if(heap[left_child] < heap[right_child])
            max_child = right_child;
        else
            max_child = left_child;

        if(heap[parent] > heap[max_child])
        {
            swap(heap[parent],heap[max_child]);
            parent = max_child;
            right_child = 2*parent + 2;
            left_child = 2*parent + 1;
        } 
        else
            break;
    }

    if(left_child<length && heap[parent]>heap[left_child])
    {
        swap(heap[parent],heap[left_child]);
    }
}


void deletemin(int heap[],int length)
{
    heap[0] = heap[--length];
    TopDownHeapify(heap,length,0);
}



int main()
{
    int n;
    cin >> n;
    int * heap = (int *)malloc(sizeof(int) * n);

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
        cout << heap[i] << " ";
    }
    cout << endl;


    int delete_index;
    cin >> delete_index;
    for(int i = 0;i < delete_index;i++)
    {
        deletemin(heap,length);
        length--;
    }

    for(int i = 0;i < length;i++) cout << heap[i] << " ";
    cout << endl;

    return 0;
}
