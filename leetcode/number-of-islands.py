class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        columns,rows = len(grid),len(grid[0])
        visit = [[False]*rows for _ in range(columns)]
        di = (-1,0,1,0)
        dj = (0,1,0,-1)
        segCheck = lambda i,j : True if 0<= i < columns and 0<= j < rows else False
        count = 0
        def dfs(curIndex,curJndex):
            visit[curIndex][curJndex] = True
            for i,j in zip(di,dj):
                nextIndex = curIndex + i
                nextJndex = curJndex + j
                if segCheck(nextIndex,nextJndex):
                    if not visit[nextIndex][nextJndex] and grid[nextIndex][nextJndex] == '1':
                        dfs(nextIndex,nextJndex)
        for i in range(columns):
            for j in range(rows):
                if grid[i][j] == '1' and not visit[i][j]:
                    dfs(i,j)
                    count += 1
        return count
