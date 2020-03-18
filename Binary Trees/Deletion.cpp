#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct node 
{
    int data;
    struct node * left;
    struct node * right;
};



struct node * newnode (int data)
{
    struct node * temp = new node;
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



void deletedeepest(struct node * root,struct node * d_node)
{
    queue <struct node *>q;
    q.push(root);
    struct node * temp;
    while(!q.empty())
    {
        temp= q.front();
        q.pop();
        if(temp == d_node)
        {
            temp = NULL;
            delete(d_node);
            return;
        }

        if(temp->right)
        {
            if(temp->right == d_node)
            {
                temp->right = NULL;
                delete(d_node);
                return;
            }
            else 
            {
                q.push(temp->right);
            }
        }


        if(temp->left)
        {
            if(temp->left == d_node)
            {
                temp->left = NULL;
                delete(d_node);
                return;
            }
            else 
            {
                q.push(temp->left);
            }
        }
    }
}



node * deletion(struct node * root,int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    
    if(root->left == NULL && root->right == NULL)
    {
        if(root->data == key)
        {
            return NULL;
        }
        else 
        {
            return root;
        }
    }


    queue <struct node *>q;
    q.push(root);

    struct node * temp;
    struct node * keynode = NULL;

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->data == key)
        {
            keynode = temp;
        }
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }

    if(keynode != NULL)
    {
        int x = temp->data;
        deletedeepest(root,temp);
        keynode->data = x;
    }

    return root;

}




int main()
{
    struct node* root = newnode(10); 
    root->left = newnode(11); 
    root->left->left = newnode(7); 
    root->left->right = newnode(12); 
    root->right = newnode(9); 
    root->right->left = newnode(15); 
    root->right->right = newnode(8); 
  
    cout << "Inorder traversal before deletion : "; 
    inorder(root); 
  
    int key = 11; 
    root = deletion(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    inorder(root);
    return 0;
}
