from itertools import combinations
from collections import deque
import copy
if __name__ == "__main__" :
    MAX=9999999999999999
    answer=MAX
    n,m=map(int,input().split())
    office=[ [0 for i in range(n)] for i in range(n)]
    AllVisit=[ [1 for i in range(n)] for i in range(n)]
    di=[-1,0,1,0]
    dj=[0,1,0,-1]
    virous=[]
    for i in range(n):
        for j , value in enumerate(list(map(int,input().split()))):
            if value==2: virous.append((i,j))
            elif value==1: office[i][j]=1
    const_Office=copy.deepcopy(office)
    def BFS(virous_list):
        office=copy.deepcopy(const_Office)
        q=deque(virous_list)
        for i,j in q:
            office[i][j]=1
        count=0
        while q:
            curVirousCount=len(q)
            count+=1
            for _ in range(curVirousCount):
                curI,curJ=q.popleft()
                for i,j in zip(di,dj):
                    newI=curI+i
                    newJ=curJ+j
                    if 0<=newI<n and 0<=newJ<n and office[newI][newJ]==0:
                        office[newI][newJ]=1
                        q.append((newI,newJ))
        return count if office==AllVisit else MAX

    for virous_list in combinations(virous,m):
        answer=min(BFS(virous_list),answer)
    print( -1 if answer==MAX else answer-1) 
