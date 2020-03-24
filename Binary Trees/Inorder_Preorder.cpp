#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct node
{
    char data;
    struct node *left,*right;
};



int search(char arr[],int start,int end,char value)
{
    int i;
    for(i = start;i <= end;i++)
    {
        if(arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}





node *newnode(char data)
{
    node * temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}



node * buildtree(char in[],char pre[],int instart,int inend)
{
    static int preindex = 0;
    if(instart > inend)
        return NULL;

    node * tnode = newnode(pre[preindex++]);
    if(instart == inend) return tnode;

    int inindex = search(in,instart,inend,tnode->data);

    tnode->left = buildtree(in,pre,instart,inindex-1);
    tnode->right = buildtree(in,pre,inindex + 1,inend);

    return tnode;
}




void printinorder(node * root)
{
    if(!root) return;

    printinorder(root->left);
    cout << root->data << " ";
    printinorder(root->right);

}






int main()
{
    char in[] = {'d','b','e','a','f','c'};
    char pre[] = {'a','b','d','e','c','f'};
    int len = sizeof(in)/sizeof(in[0]);
    node * root = buildtree(in,pre,0,len - 1);
    cout << "The inorder traversal is :" ;
    printinorder(root);
    cout << endl;
    return 0;
}
