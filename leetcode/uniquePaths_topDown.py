class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp=[[0]*n for i in range(m)]
        dp[0][0]=1
        def topDownDp(dp:list,index:int,jndex:int)->int:
            if not (0<=index<m and 0<=jndex<n): return 0
            if dp[index][jndex]!=0: return dp[index][jndex]
            dp[index][jndex]=topDownDp(dp,index-1,jndex)+topDownDp(dp,index,jndex-1)
            return dp[index][jndex]
        return topDownDp(dp,m-1,n-1)
