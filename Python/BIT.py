#git username-> DravitLochan

def getSum(BITree,j,n):
    sum=0
    j=j+1
    while(j>0):
        sum+=BITree[j]
        j=j-(j&(-j))
    return sum    



def updateTree(BITree,i,value,n):
    i=i+1
    while(i<=n):
        BITree[i]=BITree[i]+value
        i=i+(i&(-i))


if __name__ == "__main__":
    freq=[2,1,1,3,2,3,4,5,6,7,8,9]
    n=len(freq)
    BITree=[0]*(len(freq)+1)
    for i in range (0,n):
        updateTree(BITree,i,freq[i],n)
    print("Sum before update : ",getSum(BITree,5,n))
    freq[3]+=6
    updateTree(BITree,3,6,n)
    print("Sum after update : ",getSum(BITree,5,n))
