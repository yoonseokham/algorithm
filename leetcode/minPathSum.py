class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        MAX=(1000000)
        n=len(grid[0])
        m=len(grid)
        dp=[[MAX]*(n+1) for i in range(m+1)]
        grided=[[0]*(n+1) for i in range(m+1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                grided[i][j]=grid[i-1][j-1]
        dp[1][0]=0
        dp[0][1]=0
        for i in range(1,m+1):
            for j in range(1,n+1):
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grided[i][j]
        return dp[m][n]
