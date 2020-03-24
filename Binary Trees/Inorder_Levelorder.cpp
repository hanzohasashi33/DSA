#include <bits/stdc++.h>
using namespace std;



struct node 
{
    char data;
    struct node * left,*right;
};




int search(int arr[],int start,int end,int value)
{
    for(int i = start;i <= end;i++)
    {
        if(arr[i] == value)
            return i;
    }
    return -1;
}



int *extractkeys(int in[],int level[],int m,int n)
{
    int *newlevel = new int[m],j = 0;
    for(int i = 0;i < n;i++)
    {
        if(search(in,0,m-1,level[i]) != -1)
            newlevel[j] = level[i],j++;
    }
    return newlevel;
}



node *newnode(int key)
{
    node * temp = new node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp; 
}





node * buildtree(int in[],int level[],int instart,int inend,int n)
{
    if(instart > inend) return NULL;
    node * root = newnode(level[0]);

    if(instart == inend) return root;

    int inindex = search(in,instart,inend,root->data);
    int *leftlevel = extractkeys(in,level,inindex,n);
    int *rightlevel = extractkeys(in + inindex + 1,level,n - inindex - 1,n);

    root->left = buildtree(in,leftlevel,instart,inindex -1,n);
    root->right = buildtree(in,rightlevel,inindex + 1,inend,n);

    delete [] leftlevel;
    delete [] rightlevel;

    return root;
}




void printinorder(node * root)
{
    if(root)
    {
        printinorder(root->left);
        cout << root->data << " ";
        printinorder(root->right);
    }
    cout << endl;
}


int main()
{
    int in[] = {4,8,10,12,14,20,22};
    int level[] = {20,8,22,4,12,10,14};
    int n = sizeof(in)/sizeof(in[0]);
    node * root = buildtree(in,level,0,n-1,n);

    cout << "inorder traversal is :";
    printinorder(root);

    return 0;
}
