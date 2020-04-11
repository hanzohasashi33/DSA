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
  temp->height = 1;
  return (temp);
}




struct node * rightrotate(struct node * y)
{
  struct node * x = y->left;
  struct node * t2 = x->right;

  x->right = y;
  y->left = t2;

  y->height = max(height(y->left), height(y->right))+1; 
  x->height = max(height(x->left), height(x->right))+1; 

  return x;
}




struct node * leftrotate(struct node * x)
{
  struct node * y = x->right;
  struct node * t2 = y->left;

  y->left = x;
  x->right = t2;

  x->height = max(height(x->left), height(x->right))+1; 
  y->height = max(height(y->left), height(y->right))+1; 

  return y;
}



int getbalance(struct node * n)
{
  if(!n) return 0;
  return height(n->left) - height(n->right);
}




struct node * insert(struct node * root,int key)
{
  if(!root) return newnode(key);

  if(key < root->key) root->left = insert(root->left,key);
  else if(key > root->key) root->right = insert(root->right,key);
  else return root;

  root->height = 1 + max(height(root->right),height(root->left));
  int balance = getbalance(root);

  // Left Left Case 
  if (balance > 1 && key < root->left->key) 
    return rightrotate(root); 
  
  // Right Right Case 
  if (balance < -1 && key > root->right->key) 
    return leftrotate(root); 
  
  // Left Right Case 
  if (balance > 1 && key > root->left->key) 
  { 
    root->left =  leftrotate(root->left); 
    return rightrotate(root); 
  } 
  
  // Right Left Case 
  if (balance < -1 && key < root->right->key) 
  { 
    root->right = rightrotate(root->right); 
    return leftrotate(root); 
  } 
  
  return root;
}




struct node * minvaluenode(struct node * root)
{
  struct node * current = root;
  while(current->left) current = current->left;
  return current;
}




struct node* deleteNode(struct node* root, int key) 
{ 
    // STEP 1: PERFORM STANDARD BST DELETE 
  
    if (root == NULL) 
        return root; 
  
    // If the key to be deleted is smaller than the 
    // root's key, then it lies in left subtree 
    if ( key < root->key ) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the 
    // root's key, then it lies in right subtree 
    else if( key > root->key ) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is 
    // the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( (root->left == NULL) || (root->right == NULL) ) 
        { 
            struct node *temp = root->left ? root->left : root->right; 
  
            // No child case 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // One child case 
             *root = *temp; // Copy the contents of 
                            // the non-empty child 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            struct node* temp = minvaluenode(root->right); 
  
            // Copy the inorder successor's data to this node 
            root->key = temp->key; 
  
            // Delete the inorder successor 
            root->right = deleteNode(root->right, temp->key); 
        } 
    } 
  
    // If the tree had only one node then return 
    if (root == NULL) 
      return root; 
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->height = 1 + max(height(root->left), 
                           height(root->right)); 
  
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to 
    // check whether this node became unbalanced) 
    int balance = getbalance(root); 
  
    // If this node becomes unbalanced, then there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && getbalance(root->left) >= 0) 
        return rightrotate(root); 
  
    // Left Right Case 
    if (balance > 1 && getbalance(root->left) < 0) 
    { 
        root->left =  leftrotate(root->left); 
        return rightrotate(root); 
    } 
  
    // Right Right Case 
    if (balance < -1 && getbalance(root->right) <= 0) 
        return leftrotate(root); 
  
    // Right Left Case 
    if (balance < -1 && getbalance(root->right) > 0) 
    { 
        root->right = rightrotate(root->right); 
        return leftrotate(root); 
    } 
  
    return root; 
} 




void preorder(struct node * root)
{
  if(root != NULL)
  {
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
  }
}





int main()
{
  struct node * root = NULL;
  root = insert(root, 9); 
  root = insert(root, 5); 
  root = insert(root, 10); 
  root = insert(root, 0); 
  root = insert(root, 6); 
  root = insert(root, 11); 
  root = insert(root, -1); 
  root = insert(root, 1); 
  root = insert(root, 2); 

  cout << "preorder traversal is : " ;
  preorder(root);
  cout << endl;

  deleteNode(root, 10);

  cout << "preorder traversal is : " ;
  preorder(root); 
  return 0;
}
