from collections import defaultdict

def solution(str1, str2):
    preProcessA=''.join([i.lower() if i.isalpha() else " " for i in str1 ])
    multiSetA=[preProcessA[i:i+2]  for i in range(len(preProcessA)-1) if " " not in preProcessA[i:i+2]]
    preProcessB=''.join([i.lower() if i.isalpha() else " " for i in str2 ])
    multiSetB=[preProcessB[i:i+2]  for i in range(len(preProcessB)-1) if " " not in preProcessB[i:i+2]]
    
    AandB=defaultdict(int)
    AorB=defaultdict(int)
    A=defaultdict(int)
    B=defaultdict(int)
    
    for i in multiSetA:
        A[i]+=1
    for i in multiSetB:
        B[i]+=1
        
    ABkeys=set(A.keys())|set(B.keys())
    
    for i in ABkeys:
        if i in B and i in A:
            AorB[i]=max(A[i],B[i])
            AandB[i]=min(A[i],B[i])
        elif i in B:
            AorB[i]=B[i]
        elif i in A:
            AorB[i]=A[i]
    
    sumAnd=0
    sumOr=0
    
    for i,j in AandB.items():
        sumAnd+=j
    for i,j in AorB.items():
        sumOr+=j
    if sumOr==0:
        return 65536
    return int(sumAnd/sumOr*65536)
