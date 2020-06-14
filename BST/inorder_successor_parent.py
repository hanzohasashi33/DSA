class Node :
    def __init__(self,key) :
        self.key = key 
        self.left = None
        self.right = None
        self.parent = None 


def insert(root,key) :
    if root is None :
        return Node(key)
    
    if key < root.key :
        temp = insert(root.left,key)
        root.left = temp 
        temp.parent = root 
    else :
        temp = insert(root.right,key)
        root.right = temp 
        temp.parent = root 
    
    return root 

def minvalue(node) :
    current = node 
    while current :
        current = current.left 
    return current 


def inorder(root) :
    if root :
        inorder(root.left)
        print(root.key,end = " ")
        inorder(root.right)



def inorder_successor(root,n) :
    #if right subtree exists
    if n.right :
        return minvalue(n.right)

    #if there is no right subtree -> traverse the parent 
    p = n.parent 
    while p :
        if n != p.right :
            break 
        n = p 
        p = p.parent 
    return p 



if __name__ == "__main__":
    root = None
  
    root = insert(root, 20) 
    root = insert(root, 8); 
    root = insert(root, 22); 
    root = insert(root, 4); 
    root = insert(root, 12); 
    root = insert(root, 10);   
    root = insert(root, 14); 

    temp = root.left.right.right 

    inorder(root)
    print()

    succ = inorder_successor(root,temp)
    if succ is not None :
        print(temp.key,succ.key)
    else :
        print("Inorder successor does'nt exist")