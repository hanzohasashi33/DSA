class Node :
    def __init__(self,key) :
        self.key = key 
        self.left = None
        self.right = None


def insert(root,key) :
    if root is None :
        return Node(key)
    
    if key < root.key :
        root.left = insert(root.left,key)
    else :
        root.right = insert(root.right,key)
    
    return root 


def inorder(root) :
    if root :
        inorder(root.left)
        print(root.key,end = " ")
        inorder(root.right)


def LCS(root,x,y) :
    while x < root.key and y < root.key :
        root = root.left 

    while x > root.key and y > root.key :
        root = root.right 

    return root.key 



if __name__ == "__main__":
    root = None 
    root = insert(root,30)
    root = insert(root,50)
    root = insert(root,10)
    root = insert(root,15)
    root = insert(root,9)
    root = insert(root,7)
    root = insert(root,40)
    root = insert(root,60)
    root = insert(root,20)

    inorder(root)
    print()
    print(LCS(root,7,20))