from collections import deque
import sys
def init(n,m,k)->list:
    return [ [int(j) for j in sys.stdin.readline().rstrip()] for i in range(n)]
def BFS(maze:list,k)->int:
    q=deque([(0,0,0,1)])#현 위치,부신벽의 갯수,이동거리
    visit=[ set() for _ in range(k+1) ]
    visit[0].add((0,0))
    answer=1000001
    indexInfo=list(zip([-1,0,1,0],[0,1,0,-1]))
    while q:
        curIndex,curJndex,curSmashed,curMoved=q.popleft()
        if curIndex==len(maze)-1 and curJndex==len(maze[0])-1: return curMoved
        for i,j in indexInfo:
            newI=curIndex+i
            newJ=curJndex+j
            if 0<=newI<len(maze) and 0<=newJ<len(maze[0]):
                if maze[newI][newJ]==0  and (newI,newJ) not in visit[curSmashed]:
                    q.append((newI,newJ,curSmashed,curMoved+1))
                    visit[curSmashed].add((newI,newJ))
                if curSmashed<k and maze[newI][newJ]==1 and (newI,newJ) not in visit[curSmashed+1]:
                    q.append((newI,newJ,curSmashed+1,curMoved+1))
                    visit[curSmashed+1].add((newI,newJ))
    return -1 if answer==1000001 else answer
if __name__ == "__main__":
    n,m,k=map(int,sys.stdin.readline().rstrip().split())
    maze=init(n,m,k)
    print(BFS(maze,k))
