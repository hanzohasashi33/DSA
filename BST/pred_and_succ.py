class Node :
    def __init__(self,key) :
        self.key = key 
        self.left = None 
        self.right = None 


def findpresuc(root,key) :
    if root is None :
        return None 

    if root.key == key :
        #max value in left subtree is predecessor
        if root.left is not None :
            temp = root.left 
            while temp.right :
                temp = temp.right 
            findpresuc.pre = temp 


        #min value in right subtree is successor
        if root.right is not None :
            temp = root.right 
            while temp.left :
                temp = temp.left 
            findpresuc.suc = temp 
        
        return None 

    #key smaller than root's key , go to left subtree 
    if root.key > key :
        findpresuc.suc = root 
        findpresuc(root.left,key)
    
    else :
        findpresuc.pre = root 
        findpresuc(root.right,key)




def insert(node,key) :
    if node is None :
        return Node(key)

    if key < node.key :
        node.left = insert(node.left,key)
    else :
        node.right = insert(node.right,key)
    
    return node 



if __name__ == "__main__":
    key = 65 
    root = None 
    root = insert(root, 50) 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 

    findpresuc.pre = None 
    findpresuc.suc = None 

    findpresuc(root,key)

    print(findpresuc.suc.key,findpresuc.pre.key)