from collections import deque
import sys
def init(n,m,k)->list:
    return [ [int(j) for j in sys.stdin.readline().rstrip()] for i in range(n)]
def BFS(maze:list,k:int)->int:
    q=deque([(0,0,0)])#현 위치,부신벽의 갯수
    dp=[ [ [0]*len(maze[0]) for i in range(len(maze))] for _ in range(k+1) ]
    dp[0][0][0]=1
    indexInfo=list(zip([-1,0,1,0],[0,1,0,-1]))
    while q:
        curI,curJ,curSmashed=q.popleft()
        if curI==len(maze)-1 and curJ==len(maze[0])-1 and 0<=curSmashed<=k: return dp[curSmashed][curI][curJ]
        for i,j in indexInfo:
            newI=curI+i;newJ=curJ+j
            if 0<=newI<len(maze) and 0<=newJ<len(maze[0]) and 0<=curSmashed<=k:
                if not dp[curSmashed][newI][newJ] :
                    if maze[newI][newJ]==0:
                        dp[curSmashed][newI][newJ]=dp[curSmashed][curI][curJ]+1
                        q.append((newI,newJ,curSmashed))
                    elif maze[newI][newJ]==1 and curSmashed<k:
                        dp[curSmashed+1][newI][newJ]=dp[curSmashed][curI][curJ]+1
                        q.append((newI,newJ,curSmashed+1))

    return -1
if __name__ == "__main__":
    n,m,k=map(int,sys.stdin.readline().rstrip().split())
    maze=init(n,m,k)
    print(BFS(maze,k))
