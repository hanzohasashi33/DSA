#include <stdio.h>
#include <stdlib.h>
#define maxqsize 500


struct node 
{
    int data;
    struct node * left;
    struct node * right;
};


struct node ** createqueue(int * front,int * rear)
{
    struct node ** queue = (struct node **)malloc(sizeof(struct node*) * maxqsize);
    *front = *rear = 0;
    return queue;
}


void enqueue(struct node **queue,int * rear,struct node * newnode)
{
    queue[*rear] = newnode;
    (*rear) ++; 
}


struct node * dequeue(struct node **queue,int * front)
{
    (*front) ++;
    return queue[*front - 1];
}


struct node * newnode(int data)
{
    struct node * node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}



void printlevelorder(struct node * root)
{
    int rear,front;
    struct node **queue = createqueue(&front,&rear);
    struct node * temp = root;

    while(temp)
    {
        printf("%d ",temp->data);
        if(temp->left)
        {
            enqueue(queue,&rear,temp->left);
        }
        if(temp->right)
        {
            enqueue(queue,&rear,temp->right);
        }
        temp = dequeue(queue,&front);
    }
}


int main()
{
    struct node * root = newnode(1);
    root->left        = newnode(2); 
    root->right       = newnode(3); 
    root->left->left  = newnode(4); 
    root->left->right = newnode(5); 
    printlevelorder(root);
    return 0;
}
