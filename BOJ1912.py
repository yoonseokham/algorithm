def dpIniter(n,arr):
    dp=[0 for i in range(n)]
    dp[0]=arr[0]
    max=arr[0]
    for i in range(1,n):
        if dp[i-1]>0:
            dp[i]=dp[i-1]+arr[i]
        else:
            dp[i]=arr[i]
        if max<dp[i]:
            max=dp[i]
    return max
    print(dp)
n=int(input())
arr=list(map(int,input().split()))
print(dpIniter(n,arr))
