INT_MIN = float("-infinity")
INT_MAX = float("infinity")


class Node :
    def __init__(self,data) :
        self.data = data
        self.left = None 
        self.right = None 


def isBST(node,mini,maxi) :
    if node is None :
        return True 

    if node.data < mini or node.data > maxi :
        return False 

    return isBST(node.left,mini,node.data - 1) and isBST(node.right,node.data + 1,maxi)


if __name__ == "__main__":
    root = Node(4) 
    root.left = Node(2) 
    root.right = Node(5) 
    root.left.left = Node(1) 
    root.left.right = Node(3) 
  
    if (isBST(root,INT_MIN,INT_MAX)): 
        print ("Is BST")
    else: 
        print ("Not a BST")
