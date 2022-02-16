class DFS:
    def __init__(self, grid, visit):
        self._grid = grid
        self._rows = len(grid)
        self._cols = len(grid[0])
        self._didj = list(zip((-1,0,1,0),(0,1,0,-1)))
        self._visit = visit
    def __call__(self, index ,jndex):
        self._visit[index][jndex] = True
        for i, j in self._didj:
            newI = i + index
            newJ = j + jndex
            if 0 <= newI < self._rows and 0<= newJ < self._cols:
                if not self._visit[newI][newJ] and self._grid[newI][newJ] == '1':
                    self.__call__(newI,newJ)
        
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visit = [[False]*len(grid[0]) for _ in range(len(grid))]
        dfs = DFS(grid,visit)
        answer = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if not visit[i][j] and grid[i][j] == '1':
                    answer += 1
                    dfs(i,j)
        return answer
