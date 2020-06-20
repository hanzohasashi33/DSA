import math
import sys 

INT_MAX = float("inf")


def getMid(ss,se) :
    return ss + (se - ss)//2 





def update(tree,arr,ss,se,i,new_value,si) :
    if i < ss or i > se :
        #print("Invalid Input")
        return 

    if ss == se :
        arr[i] = new_value
        tree[si] = new_value
    
    else :
        mid = getMid(ss,se)
        update(tree,arr,ss,mid,i,new_value,2*si+1)
        update(tree,arr,mid+1,se,i,new_value,2*si+2)
        tree[si] = min(tree[2*si+1],tree[2*si+2])






def RMQUTil(tree,ss,se,qs,qe,si) :
    #part of given range
    if qs <= ss and qe >= se :
        return tree[si]    

    #outside the given range
    if se < qs or ss > qe :
        return INT_MAX 
    
    mid = getMid(ss,se)
    return min(RMQUTil(tree,ss,mid,qs,qe,2*si+1),RMQUTil(tree,mid+1,se,qs,qe,2*si+2))




#range min query
def RMQ(tree,n,qs,qe) :
    if qs < 0 or qe > n - 1 or qs > qe :
        print("Invalid Input")
        print()
        return -1 

    return RMQUTil(tree,0,n-1,qs,qe,0)




#ss - segment start se - segment end 
#si - index of current node in tree
def constructTreeUtil(arr,ss,se,tree,si) :
    if ss == se :
        tree[si] = arr[ss]
        return arr[ss]
    
    mid = getMid(ss,se)
    tree[si] = min(constructTreeUtil(arr,ss,mid,tree,2*si + 1),constructTreeUtil(arr,mid+1,se,tree,2*si+2))
    return tree[si]



def constructTree(arr,n) :
    x = (int)(math.ceil(math.log2(n)))
    max_size = 2 * (int)(2**x) - 1   #size of binary tree is 2*n - 1
    tree = [0] * max_size
    constructTreeUtil(arr,0,n-1,tree,0)
    return tree 




if __name__ == "__main__":
    arr = [1,3,4,2,6,5]
    n = len(arr)
    tree = constructTree(arr,n)
    print(tree)
    qs = 1
    qe = 5
    print(RMQ(tree,n,qs,qe))
    update(tree,arr,0,n-1,3,10,0)
    print(arr)
    print(tree)