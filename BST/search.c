#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct node
{
    int key;
    struct node * left,*right;
};


struct node * newnode(int key)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
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




struct node * search(struct node * root,int key)
{
    if(root == NULL || root->key == key)
    {
        return root;
    }

    if(root->key < key)
    {
        return search(root->right,key);
    }
    return search(root->left,key);
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
    printf("\n");
    struct node * current = search(root,60);
    printf("%d ",current->key);
    return 0;
}
