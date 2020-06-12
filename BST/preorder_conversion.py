# Write your code here
class Node :
    def __init__(self,data) :
        self.data = data 
        self.left = None 
        self.right = None 


class BinaryTree :
    def constructtree(self,pre,size) :
        root = Node(pre[0])
        s = []
        s.append(root)
        i = 1 
        while i < size :
            temp = None 
            while(len(s) > 0 and pre[i] > s[-1].data) :
                temp = s.pop()
            
            if temp != None :
                temp.right = Node(pre[i])
                s.append(temp.right)

            else :
                temp = s[-1]
                temp.left = Node(pre[i])
                s.append(temp.left)
            i += 1
        return root 

def maxDepth(node): 
    if node is None: 
        return 0 ;  
  
    else : 
  
        # Compute the depth of each subtree 
        lDepth = maxDepth(node.left) 
        rDepth = maxDepth(node.right) 
  
        # Use the larger one 
        if (lDepth > rDepth): 
            return lDepth+1
        else: 
            return rDepth+1

if __name__ == "__main__":
    tree = BinaryTree()
    n = int(input())
    l = list(map(int,input().split()))
    root = tree.constructtree(l,n)
    print(maxDepth(root))
