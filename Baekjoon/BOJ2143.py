import sys
from collections import Counter
from collections import defaultdict
from itertools import combinations

def SumArrayMaker(array:list)->list:
    sumArray=[0,array[1]]
    for i in range(2,len(array)):
        sumArray.append(array[i]+sumArray[i-1])
    return sumArray

def sumIJ(array:list):
    def returnFunc(i:int,j:int):
        temp=array
        return array[j]-array[i-1]
    return returnFunc

if __name__ == "__main__":
    target=int(sys.stdin.readline().rstrip())
    n=int(sys.stdin.readline().rstrip())
    Aarray=[0]
    Barray=[0]
    Aarray.extend(list(map(int,sys.stdin.readline().rstrip().split())))
    m=int(sys.stdin.readline().rstrip())
    Barray.extend(list(map(int,sys.stdin.readline().rstrip().split())))
    Asum=SumArrayMaker(Aarray)
    Bsum=SumArrayMaker(Barray)
    getIJA=sumIJ(Asum)
    getIJB=sumIJ(Bsum)
    pickIJA=list(combinations(list(range(1,len(Aarray))),2))
    pickIJB=list(combinations(list(range(1,len(Barray))),2))
    pickIJA.extend([(i,i) for i in range(1,len(Aarray))])
    pickIJB.extend([(i,i) for i in range(1,len(Barray))])
    sum=0
    A=Counter((getIJA(i,j) for i,j in pickIJA))
    B=Counter((getIJB(i,j) for i,j in pickIJB))
    del Asum,Bsum,pickIJA,pickIJB,Aarray,Barray
    for key,value in A.items():
        if B[target-key]:
            sum+=B[target-key]*value
    print(sum)
