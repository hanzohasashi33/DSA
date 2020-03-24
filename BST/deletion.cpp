#include <bits/stdc++.h>
using namespace std ;


struct node 
{
    int key;
    struct node *left,*right;
};



struct node * newnode(int item)
{
    struct node * temp = new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}



void inorder(struct node * root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}



struct node * insert(struct node * root,int key)
{
    if(root == NULL) return newnode(key);

    if(key < root->key)
        root->left = insert(root->left,key);
    else if(key > root->key)
        root->right = insert(root->right,key);
    
    return root;
}




struct node * minvaluenode(struct node * root)
{
    struct node * current = root;
    while(current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}



struct node * deletenode(struct node * root,int key)
{
    if(root==NULL) return root;

    if(key < root->key)
        root->left = deletenode(root->left,key);
    else if(key > root->key)
        root->right = deletenode(root->right,key);
    else 
    {
        if(root->left == NULL)       //node with only one child or no child
        {
            struct node * temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node * temp = root->left;
            free(root);
            return temp;
        }

        //if both children exists
        struct node * temp = minvaluenode(root->right);
        root->key = temp->key;
        root->right = deletenode(root->right,temp->key);
    }
    return root;
}


int main()
{
    struct node * root = NULL;
    root = insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);

    inorder(root);
    cout << endl;

    
    root = deletenode(root,20);
    inorder(root);
    cout << endl;

    root = deletenode(root,30);
    inorder(root);
    cout << endl;

    root = deletenode(root,50);
    inorder(root);
    cout << endl;
    return 0;
}
