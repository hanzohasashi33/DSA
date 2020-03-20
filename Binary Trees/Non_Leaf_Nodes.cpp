#include <bits/stdc++.h>
using namespace std;


struct node 
{
    int data;
    struct node * left,* right;
};



struct node * newnode(int data)
{
    struct node * temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}



int nonleafnodes(struct node * root)
{
    if(root == NULL || root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    return nonleafnodes(root->left) + 1 + nonleafnodes(root->right);
}



int main()
{
    struct node * root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    cout << "No of nonleafnodes is : " << nonleafnodes(root) << endl;
    return 0;
}
