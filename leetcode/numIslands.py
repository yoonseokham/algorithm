class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visit=[[False]*len(grid[0]) for i in range(len(grid))]
        count=0
            
        def dfs(grid:list,visit:list,index:int,jndex:int)->None:
            for i in range(4):
                newI=index+int("0121"[i])-1
                newJ=jndex+int("1210"[i])-1
                if 0<=newI<len(grid) and 0<=newJ<len(grid[0]) and visit[newI][newJ]==False and grid[newI][newJ]=="1":
                    visit[newI][newJ]=True
                    dfs(grid,visit,newI,newJ)
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if not visit[i][j] and grid[i][j]=="1":
                    count+=1
                    visit[i][j]=True
                    dfs(grid,visit,i,j)
        return count
        
