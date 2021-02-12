def MaxWithOutJ(arr,j):
    Max=0
    for i in range(len(arr)):
        if i == j:
            continue
        elif Max<arr[i]:
            Max=arr[i]
    return Max

def solution(land):
    dp=[[0 for i in range(len(land[0]))] for i in range(len(land))]
    for i in range(len(land[0])):
        dp[0][i]=land[0][i]
    for i in range(1,len(land)):
        for j in range(0,len(land[0])):
            dp[i][j]=land[i][j]+MaxWithOutJ(dp[i-1],j)
    return max(dp[len(land)-1])
