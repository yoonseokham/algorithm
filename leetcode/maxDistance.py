from collections import deque
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        max_dist=-1
        visit=[[0 for i in range(len(grid))] for i in range(len(grid))]
        def BFS(startI:int,startJ:int):
            visit[startI][startJ]=1
            q=deque([(startI,startJ)])
            while q:
                curI,curJ=q.popleft()
                for i in range(4):
                    newI=curI+int("0121"[i])-1
                    newJ=curJ+int("1210"[i])-1
                    if 0<=newI<len(grid) and 0<=newJ<len(grid) and grid[newI][newJ]==0:
                            if visit[newI][newJ]==0 or visit[newI][newJ]>visit[curI][curJ]+1:
                                visit[newI][newJ]=visit[curI][curJ]+1
                                q.append((newI,newJ))
        for i in range(0,len(grid)):
            for j in range(0,len(grid)):
                if grid[i][j]==1:
                    BFS(i,j)
        answer=lambda x: -1 if x==0 else x
        return answer(max([max(i) for i in visit])-1)
