import sys
import heapq
MAX = 10000000
m,n=map(int,input().split())
map=[[0 for i in range(m)] for i in range(n)]
dp=[[MAX for i in range(m)] for i in range(n)]

for i in range(n):
    line=sys.stdin.readline().rstrip()
    for j in range(len(line)):
        map[i][j]=int(line[j])

def segCheck(i,j):
    global m,n
    if i>=0 and i<n and j>=0 and j<m:
        return True
    return False
def bfs(curI=0,curJ=0):
    hq=[[0,curI,curJ]]
    global map,dp,n,m
    while dp[n-1][m-1]==MAX:
        cost,curI,curJ=heapq.heappop(hq)
        for i in range(4):
            NewI=curI+int("0121"[i])-1
            NewJ=curJ+int("1210"[i])-1
            if segCheck(NewI,NewJ) and dp[NewI][NewJ]>dp[curI][curJ]:
                if map[NewI][NewJ]==0:
                    dp[NewI][NewJ]=min(dp[curI][curJ],dp[NewI][NewJ])
                    heapq.heappush(hq,[dp[NewI][NewJ],NewI,NewJ])
                else if dp[curI][curJ]+1<dp[NewI][NewJ]:
                    dp[NewI][NewJ]=min(dp[curI][curJ]+1,dp[NewI][NewJ])
                    heapq.heappush(hq,[dp[NewI][NewJ],NewI,NewJ])
dp[0][0]=0
bfs()
print(dp[n-1][m-1],end='')
