#include <iostream>
#include <bits\stdc++.h>
using namespace std;


struct node 
{
    int data;
    struct node * left;
    struct node * right;
};




struct node * newnode(int data)
{
    struct node * temp = new node ;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


void inorder(struct node * temp)
{
    if(!temp)
        return;

    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}




void insert(struct node * temp,int key)
{
    queue<struct node *>q;
    q.push(temp);

    while(!q.empty())
    {
        struct node * temp = q.front();
        q.pop();
    

        if(!temp->left)
        {
            temp->left = newnode(key);
            break;
        }
        else 
        {
            q.push(temp->left);
        }



        if(!temp->right)
        {
            temp->right=  newnode(key);
            break;
        }
        else 
        {
            q.push(temp->right);
        }
    }
}


int main()
{
    struct node* root = newnode(10); 
    root->left = newnode(11); 
    root->left->left = newnode(7); 
    root->right = newnode(9); 
    root->right->left = newnode(15); 
    root->right->right = newnode(8); 
  
    cout << "Inorder traversal before insertion:"; 
    inorder(root); 
  
    int key = 12; 
    insert(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after insertion:"; 
    inorder(root); 
    return 0;
}
