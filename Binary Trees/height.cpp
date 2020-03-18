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
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}




int height(struct node * root)
{
    if(root == NULL) return 0;
    else 
    {
        int ldepth = height(root->left);
        int rdepth = height(root->right);

        if(ldepth > rdepth)
        {
            return ldepth + 1;
        }
        else 
        {
            return rdepth + 1;
        }
    }
}








int main()
{
    struct node * root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->right = newnode(4);
    root->left->right = newnode(5);
    cout << height(root) << endl;
    return 0;
}
