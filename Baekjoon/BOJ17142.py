from collections import deque
from itertools import combinations
if __name__ == "__main__":
    MAX =99999999
    n,m=map(int,input().split())
    initialState=[list(map(int,input().rstrip().split())) for _ in range(n)]
    virousLocation=[ (i,j) for j in range(n) for i in range(n) if initialState[i][j]==2]
    def BFS(dq,answer):
        cnt=0
        activateState=[[ 0 if j==2 else j for j in i]  for i in initialState]
        di=[-1,0,1,0]
        dj=[0,1,0,-1]
        for i,j in dq:
            activateState[i][j]=2
        q=deque(dq)
        notInfested=set( (i,j) for j in range(n) for i in range(n) if initialState[i][j]==0)
        while len(notInfested)>0 and cnt<answer:
            temp=0
            qLength=len(q)
            for _ in range(qLength):
                curI,curJ=q.popleft()
                for k in range(4):
                    newI=curI+di[k]
                    newJ=curJ+dj[k]
                    if 0<=newI<n and 0<=newJ<n and activateState[newI][newJ]==0:
                        temp+=1
                        q.append((newI,newJ))
                        activateState[newI][newJ]=2
                        notInfested.discard((newI,newJ))
            if temp==0:
                return MAX
            cnt+=1
        return cnt
    answer=MAX
    combi=combinations(virousLocation,m)
    for dq in combi:
        answer=min(BFS(dq,answer),answer)
        if answer==0: break
    print(-1 if answer==MAX else answer)