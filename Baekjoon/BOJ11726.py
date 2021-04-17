def dpIniter(n):
    dp=[ 0 for i in range(1001)]
    dp[1]=1
    dp[2]=2
    for i in range(3,n+1):
        dp[i]=dp[i-1]%10007+dp[i-2]%10007
        dp[i]%10007
    return dp[n]% 10007
n=int(input())
print(dpIniter(n))
