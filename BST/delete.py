import os
import sys
import re 
import collections 


class Node :
    def __init__(self,key) :
        self.key = key
        self.left = None 
        self.right = None 
        


def inorder(root) :
    if root :
        inorder(root.left)
        print(root.key,end = " ")
        inorder(root.right)


def insert(node,key) :
    if node is None :
        return Node(key) 
    
    if key < node.key :
        node.left = insert(node.left,key)
    else :
        node.right = insert(node.right,key)

    return node 

def minValueNode(node) :
    current = node 
    while current.left is not None :
        current = current.left 
    
    return current


def deletenode(root,key) :
    #base case 
    if root is None :
        return root 
    
    if key < root.key :
        root.left = deletenode(root.left,key)
    
    elif key > root.key :
        root.right = deletenode(root.right,key)
    
    else :
        #one or no child 
        if root.left is None :
            temp = root.right 
            root = None 
            return temp 
        
        elif root.right is None :
            temp = root.left 
            root = None 
            return temp 

        #two children 
        temp = minValueNode(root.right) 
        root.key = temp.key 
        root.right = deletenode(root.right,temp.key)

    return root 


if __name__ == "__main__":
    root = None 
    root = insert(root,50)
    root = insert(root,30)
    root = insert(root, 20) 
    root = insert(root, 40) 
    root = insert(root, 70) 
    root = insert(root, 60) 
    root = insert(root, 80) 

    inorder(root)
    print()

    root = deletenode(root,10)
    inorder(root)
    print()

    root = deletenode(root,50)
    inorder(root)
    print()