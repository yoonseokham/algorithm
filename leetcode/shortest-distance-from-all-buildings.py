import collections
class Solution:
    def getDistanceByBFS(self, start, grid: List[List[int]], reachable):
        didj = tuple(zip((-1,0,1,0),(0,1,0,-1)))
        q = collections.deque([start])
        visit = [[-1 for _ in grid[0]] for _ in grid ]
        visit[start[0]][start[1]] = 0
        early_kill = [[-1 for _ in grid[0]] for _ in grid ]
        while q:
            curPoint = q.popleft()
            for i,j in didj:
                newI = curPoint[0] + i
                newJ = curPoint[1] + j
                if 0<= newI < len(grid) and 0<= newJ < len(grid[0]):
                    if visit[newI][newJ] == -1 and not grid[newI][newJ]:
                        visit[newI][newJ] = 1 + visit[curPoint[0]][curPoint[1]]
                        q.append((newI,newJ))
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if visit[i][j] == -1:
                    reachable.discard((i, j))
        visit[start[0]][start[1]] = -1
        return visit, early_kill == visit
    
    def shortestDistance(self, grid: List[List[int]]) -> int:
        total_visit = [[ 0 for _ in grid[0]] for _ in grid ]
        visit_list = []
        reachable = set()
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if not grid[i][j]:
                    reachable.add((i, j))

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    visit, early_kill = self.getDistanceByBFS((i,j), grid, reachable)
                    visit_list.append(visit)
                    if not reachable or early_kill:
                        return -1

        for visit in visit_list:
            for i, _ in enumerate(grid):
                for j, _ in enumerate(grid[i]):
                    total_visit[i][j] += visit[i][j]
        
        return min(total_visit[i][j] for i,j in list(reachable))
                    
