class Solution {
public:
    void robotMover(vector<vector<int>>&dp,int m, int n,int curI=0,int curJ=0){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1]=1;
        robotMover(dp,m,n);
        return dp[m][n];
    }
};
