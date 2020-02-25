#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};


struct node * newnode(int data)
{
    struct node * node = (struct node *)malloc(sizeof(struct node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}




void printpostorder(struct node * node)
{
    if(node == NULL)
    {
        return ;
    }
    else 
    {
        printpostorder(node->left);
        printpostorder(node->right);
        printf("%d ",node->data);
    }
}




void printpreorder(struct node * node)
{
    if(node == NULL)
    {
        return ;
    }
    
    printf("%d ",node->data);
    printpreorder(node->left);
    printpreorder(node->right);
}




int main()
{
    struct node * root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    printpreorder(root);
    printf("\n");
    printpostorder(root);
    return 0;
}
