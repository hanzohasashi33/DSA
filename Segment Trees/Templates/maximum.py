import math 

INT_MIN = float("-inf")
INT_MAX = float("inf")


def getMid(s,e) :
    return s + (e-s)//2


def update(arr,tree,ss,se,i,new_value,si) :
    if i < ss or i > se :
        print("Invalid Input")
        return

    if ss == se :
        arr[i] = new_value
        tree[si] = new_value

    else :
        mid = getMid(ss,se)
        if i >= ss and i <= mid :
            update(arr,tree,ss,mid,i,new_value,2*si+1)
        else :
            update(arr,tree,mid+1,se,i,new_value,2*si+2)
        tree[si] = max(tree[2*si+1],tree[2*si+2])




def MaxUtil(tree,ss,se,l,r,si) :
    #completely inside 
    if l <= ss and r >= se :
        return tree[si]
    
    #completely outside
    if se < l or ss > r :
        return -1
     
    #partly inside
    mid = getMid(ss,se)
    return max(MaxUtil(tree,ss,mid,l,r,2*si+1),MaxUtil(tree,mid+1,se,l,r,2*si+2))




def getMax(tree, n, l, r): 
      
    if (l < 0 or r > n - 1 or l > r): 
        printf("Invalid Input") 
        return -1
  
    return MaxUtil(tree, 0, n - 1, l, r, 0) 





#ss - segment start se - segment end 
#si - index of current node in tree
def constructTreeUtil(arr,ss,se,tree,si) :
    if ss == se :
        tree[si] = arr[ss]
        return arr[ss]
    
    mid = getMid(ss,se)
    tree[si] = max(constructTreeUtil(arr,ss,mid,tree,2*si + 1),constructTreeUtil(arr,mid+1,se,tree,2*si+2))
    return tree[si]


def buildtree(arr,n) :
    x = (int)(math.ceil(math.log2(n)))
    max_size = 2 * (int)(2**x) - 1   #size of binary tree is 2*n - 1
    tree = [0] * max_size
    constructTreeUtil(arr,0,n-1,tree,0)
    return tree 





if __name__ == "__main__":
    arr = [4,1,3,2,8,12,14]
    n = len(arr)
    tree = buildtree(arr,n)
    print(tree)
    update(arr,tree,0,n-1,2,10,0)
    print(tree)
    print(getMax(tree,n,2,4))
