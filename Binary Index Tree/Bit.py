def getSum(BITTree,i) :
    s = 0
    i += 1
    while i > 0 :
        s += BITTree[i]
        i -= i & (-i)
    return s 





def updateBIT(BITTree,n,i,value) :
    i += 1
    while i <= n :
        BITTree[i] += value  
        i += i & (-i)



def construct(arr,n) :
    BITTree = [0] * (n+1)
    for i in range(n) :
        updateBIT(BITTree,n,i,arr[i])
    return BITTree



if __name__ == "__main__":
    arr = list(map(int,input().split()))
    tree = construct(arr,len(arr))
    print("Sum of 0->5 is",str(getSum(tree,5)))