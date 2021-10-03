import sys
if __name__ == '__main__':
    n,k,r=map(int,sys.stdin.readline().split())
    road=set()
    cow=list()
    didj=tuple(zip((-1,0,1,0),(0,1,0,-1)))
    answer=0
    segcheck= lambda i,j: True if 0<=i<n and 0<=j<n else False
    for _ in range(r):
        startI,startJ,endI,endJ=map(int,sys.stdin.readline().split())
        start=(startI-1,startJ-1)
        end=(endI-1,endJ-1)
        road.add((start,end))
        road.add((end,start))
    for _ in range(k):
        cowI,cowJ=map(int,sys.stdin.readline().split())
        cow.append((cowI-1,cowJ-1))

    def from_this_cow_visit_all(cow_i,cow_j):
        visit=[[False]*n for _ in range(n)]
        visit[cow_i][cow_j]=True
        cow_visit=[False]*k
        def dfs(curI,curJ):
            for index,jndex in didj:
                newI=curI+index
                newJ=curJ+jndex
                start=(curI,curJ)
                end=(newI,newJ)
                if segcheck(newI,newJ) and not visit[newI][newJ] and (start,end) not in road:
                    visit[newI][newJ]=True
                    dfs(newI,newJ)
        dfs(cow_i,cow_j)
        for i in range(k):
            index,jndex=cow[i]
            if visit[index][jndex]:
                cow_visit[i] = True
        return cow_visit
    for i,cowIJ in enumerate(cow):
        for value in from_this_cow_visit_all(*cowIJ)[i+1:]:
            if not value:
                answer+=1
    print(answer)
