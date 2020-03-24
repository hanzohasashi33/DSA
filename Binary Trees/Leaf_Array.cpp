#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int p = 0;


struct node 
{
	int data;
	struct node *left,*right;
};


struct node * newnode(int key) 
{
	struct node * temp = new node;
	temp->left = temp->right = NULL;
	temp->data = key;
	return temp;
}





void leafarr(struct node * root,int arr[])
{
	if(!root) return ;
	
	if(!root->left && !root->right) 
		arr[p++] = root->data;

	if(root->left)
		leafarr(root->left,arr);
	if(root->right)
		leafarr(root->right,arr);
}






int leafcount(struct node * root)
{
	if(!root) return 0;

	if(root->left == NULL && root->right == NULL)
		return 1;

	return leafcount(root->left) + leafcount(root->right);
}
	







int main()
{
	struct node * root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	int arr[10000];
	leafarr(root,arr);
	int n = leafcount(root);
	for(int k = 0;k < n;k++)
		cout << arr[k] << " ";
    cout << endl;	
	return 0;
}
