#include <iostream>
#include <bits/stdc++.h>
using namespace std;



struct node 
{
    int data;
    struct node * left;
    struct node * right;
};




struct node * newnode(int data)
{
    struct node * temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}






int main()
{
    struct node * root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    return 0;
}
