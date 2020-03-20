#include <bits\stdc++.h>
using namespace std;



struct node 
{
    int data;
    struct node * left,*right;
};



struct node * newnode(int data)
{
    struct node * temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


bool search(struct node * root,int x)
{
    if(root == NULL) return false;

    queue <node *> q;
    q.push(root);

    while(!q.empty())
    {
        node * node = q.front();
        if(node->data == x)
        {
            return true;
        }

        q.pop();
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }

    return false;
}



int main()
{
    struct node * root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    cout << "is 20 there : " << search(root,20) << endl;
    return 0;
}
