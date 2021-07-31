import copy
if __name__ == "__main__":    
    dindex=[-1,-1,0,1,1,1,0,-1]
    djndex=[0,1,1,1,0,-1,-1,-1]
    n,m,k=map(int,input().split())
    answer=0
    initialState=[ [ list() for j in range(n)]  for i in range(n)] #질량 속력 방향
    for _ in range(m):
        ri,ci,mi,si,di=map(int,input().split())
        initialState[ri-1][ci-1].append([mi,si,di])
    currentState=copy.deepcopy(initialState)
    def isAllEven(fireBallList:list)->bool:
        for m,s,d in fireBallList:
            if d%2!=0:
                return False
        return True

    def isAllOdd(fireBallList:list)->bool:
        for m,s,d in fireBallList:
            if d%2==0:
                return False
        return True
    
    def fireBallMover():
        global currentState
        temp=[ [ list() for j in range(n)]  for i in range(n)]
        for i in range(n):
            for j in range(n):
                for mi,si,di in currentState[i][j]:
                    if mi!=0:
                        newI=((i+si*dindex[di])+n*1000000)%n
                        newJ=((j+si*djndex[di])+n*1000000)%n
                        temp[newI][newJ].append([mi,si,di])
        for i in range(n):
            for j in range(n):
                if len(temp[i][j])>1:
                    sumOfM=sum(m for m,s,d in temp[i][j])
                    sumOfD=sum(s for m,s,d in temp[i][j])
                    newM=int(sumOfM/5)
                    newD=int(sumOfD/len(temp[i][j]))
                    if newM!=0:
                        if isAllEven(temp[i][j]) or isAllOdd(temp[i][j]):
                            temp[i][j]=[[newM,newD,0],[newM,newD,2],[newM,newD,4],[newM,newD,6]]
                        else:
                            temp[i][j]=[[newM,newD,1],[newM,newD,3],[newM,newD,5],[newM,newD,7]]
                    else: temp[i][j]=[]

        currentState=copy.deepcopy(temp)
    for _ in range(k):
        fireBallMover()
    for i in range(n):
        for j in range(n):
            for m,s,d in currentState[i][j]:
                answer+=m
    print(answer)