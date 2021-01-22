import math
def solution(n):
    primeNum=[True for i in range(n+1)]
    i=2
    primeNum[0]=False
    primeNum[1]=False
    for i in range(2,int(math.sqrt(n))+1):
        if primeNum[i]:
            for j in range(2*i,n+1,i):
                primeNum[j]=False
    prime=[i for i in primeNum if i==True]
    answer = len(prime)
    return answer
