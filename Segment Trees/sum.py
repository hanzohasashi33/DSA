import math



def getMid(s,e) :
    return s + (e-s)//2



def getSumUtil(tree,ss,se,qs,qe,si) :
    #query part of given range
    if qs <= ss and qe >= se :
        return tree[si]
    
    #query outside given range
    if se < qs or ss > qe :
        return 0 
    
    mid = getMid(ss,se)
    return getSumUtil(tree,ss,mid,qs,qe,2*si+1) + getSumUtil(tree,mid+1,se,qs,qe,2*si+2)





#qs - query start qe - query end
def getSum(tree,n,qs,qe) :
    if qs < 0 or qe > n - 1 or qs > qe :
        print("Invalid input",end = " ")
        print()
    return getSumUtil(tree,0,n-1,qs,qe,0)







def updateValueUtil(tree,ss,se,i,diff,si) :

    #index outside given range
    if i < ss or i > se :
        return 

    #index in range
    tree[si] = tree[si] + diff 
    if se != ss :
        mid = getMid(ss,se)
        updateValueUtil(tree,ss,mid,i,diff,2*si+1)
        updateValueUtil(tree,mid+1,se,i,diff,2*si+2)




def updateValue(arr,tree,n,i,new_value) :
    if i < 0 or i > n - 1 :
        print("Invalid Input",end = " ")
        return 
    
    difference = new_value - arr[i]
    arr[i] = new_value 
    updateValueUtil(tree,0,n-1,i,difference,0)





#ss - segment start se - segment end 
#si - index of current node in tree
def constructTreeUtil(arr,ss,se,tree,si) :
    if ss == se :
        tree[si] = arr[ss]
        return arr[ss]
    
    mid = getMid(ss,se)
    tree[si] = constructTreeUtil(arr,ss,mid,tree,2*si + 1) +\
               constructTreeUtil(arr,mid+1,se,tree,2*si+2)
    return tree[si]



def constructTree(arr,n) :
    x = (int)(math.ceil(math.log2(n)))
    max_size = 2 * (int)(2**x) - 1   #size of binary tree is 2*n - 1
    tree = [0] * max_size
    constructTreeUtil(arr,0,n-1,tree,0)
    return tree 




if __name__ == "__main__":
    arr = list(map(int,input().split()))
    n = len(arr)
    tree = constructTree(arr,n)
    print(tree)
    #get sum from 1->3 
    print(getSum(tree,n,1,3))
    updateValue(arr,tree,n,1,10)   # set arr[1] = 10
    print(tree)
    #get sum from 1->3
    print(getSum(tree,n,1,3))