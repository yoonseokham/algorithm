class Solution {
public:
    bool segCheck(int i,int j,int m, int n){
        return (0<=i && i<m && 0<=j&& j<n);
    }
    int robotMover(vector<vector<int>>&dp,int m, int n,int curI,int curJ){
        if(!segCheck(curI,curJ,m,n)) return 0;
        else{
            if( dp[curI][curJ]!=0) return dp[curI][curJ];
            else
                return dp[curI][curJ]=robotMover(dp,m,n,curI-1, curJ)+robotMover(dp,m,n,curI, curJ-1);
        }
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        robotMover(dp,m,n,m-1,n-1);
        return dp[m-1][n-1];
    }
};
