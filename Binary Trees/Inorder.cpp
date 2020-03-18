#include <bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    struct node * left;
    struct node * right;
    node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};



void inorder(struct node * root)
{
    if(!root)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}






void inorder_stack(struct node * root)
{
    stack <node *>s;
    node * current = root;

    while(current != NULL || s.empty() == false)
    {
        while(current != NULL)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }

}





int main()
{
    struct node * root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    inorder(root);
    cout << "\n";
    inorder_stack(root);
    return 0;
}
