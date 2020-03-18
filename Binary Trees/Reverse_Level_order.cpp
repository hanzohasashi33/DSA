#include <bits\stdc++.h>
using namespace std;


struct node 
{
    int data;
    struct node * left, * right;
};



node * newnode(int data)
{
    struct node * temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}




void reverselevelorder(node * root)
{
    stack <node *>s;
    queue <node *>q;
    q.push(root);

    while(!q.empty())
    {
        root = q.front();
        q.pop();
        s.push(root);

        if(root->right)
        {
            q.push(root->right);
        }
        if(root->left)
        {
            q.push(root->left);
        }
    }

    while(!s.empty())
    {
        root = s.top();
        cout << root->data << " ";
        s.pop();
    }
}




int main()
{
    struct node *root = newnode(1); 
    root->left        = newnode(2); 
    root->right       = newnode(3); 
    root->left->left  = newnode(4); 
    root->left->right = newnode(5); 
    root->right->left  = newnode(6); 
    root->right->right = newnode(7); 
  
    cout << "Level Order traversal of binary tree is \n"; 
    reverselevelorder(root); 
    return 0;
}
