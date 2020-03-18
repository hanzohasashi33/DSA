#include <bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    struct node * left,*right;
};



void printlevelorder(node * root)
{
    if(root == NULL) return;

    queue <node *> q;
    q.push(root);

    while(!q.empty())
    {
        node * temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
}



node * newnode(int data)
{
    node * temp = new node ;
    temp->data = data;
    temp->left = temp->right =NULL;
    return temp;
}



int main()
{
    node * root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    printlevelorder(root);
    return 0;
}
