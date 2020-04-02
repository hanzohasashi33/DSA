#include <iostream>
#include <bits/stdc++.h>
using namespace std;



struct node 
{
  int key;
  struct node * left;
  struct node * right;
  int height;
};



int height(struct node * n)
{
  if(!n) return 0;
  return n->height;
}



struct node * newnode(int key)
{
  struct node * temp = (struct node *)malloc(sizeof(struct node));
  temp->key = key;
  temp->left = temp->right = NULL;
  temp->height = 1;    //new node is basically leaf
  return temp;
}


struct node * leftrotate(struct node * x)
{
  struct node * y = x->right;
  struct node *t2 = y->left;

  y->left = x;
  x->right = t2;

  x->height = (max(height(x->left),height(x->right))) + 1;
  y->height = (max(height(y->left),height(y->right))) + 1;

  return y;
}




struct node * rightrotate(struct node * y)
{
  struct node * x = y->left;
  struct node * t2 = x->right;

  x->right = y;
  y->left = t2;

  y->height = max(height(y->left),height(y->right)) + 1;
  x->height = max(height(x->left),height(x->right)) + 1;

  return x;
}



int getbalance(struct node * n)
{
  if(!n) return 0;
  return height(n->left) - height(n->right);
}




struct node * insert(struct node * root,int key)
{
  if(!root) return newnode(key);

  if(key < root->key)
  {
    root->left = insert(root->left,key);
  }
  else if(key > root->key)
  {
    root->right = insert(root->right,key);
  }
  else return root;

  root->height = max(height(root->left),height(root->right)) + 1;

  int balance = getbalance(root);

  //4 cases
  //left left case 

  if(balance > 1 && key < root->left->key)
  {
    return rightrotate(root);
  }

  //right right case 
  if(balance < -1 && key > root->right->key)
  {
    return leftrotate(root);
  }

  //left right case 
  if(balance > 1 && key > root->left->key)
  {
    root->left = leftrotate(root->left);
    return rightrotate(root);
  }

  //right left case
  if(balance < -1 && key < root->right->key)
  {
    root->right = rightrotate(root->right);
    return leftrotate(root);
  }

  return root;
}




void preorder(struct node * root)
{
  if(!root) return ;

  cout << root->key << " ";
  preorder(root->left);
  preorder(root->right);
}




int main()
{
  struct node * root = NULL;
  root = insert(root,10);
  root = insert(root,20);
  root = insert(root,30);
  root = insert(root,50);
  root = insert(root,40);
  root = insert(root,25);

  cout << "Preorder Traversal of AVL tree is : " ;
  preorder(root);

  return 0;
}
