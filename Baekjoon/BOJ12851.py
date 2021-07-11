from collections import deque
MAX =(100001)
def BFS(start,end):
    dp = [ [0,0] for i in range(MAX)]
    dp[start]=[1,1]
    q=deque([start])
    while q :
        curLocation=q.popleft()
        for i in [-1,1,curLocation]:
            newLocation=curLocation+i
            if dp[end][0]!=0 and dp[end][0]<dp[curLocation][0]: continue
            if 0<= newLocation and newLocation<MAX and ( dp[newLocation][1]==0 or dp[newLocation][0]==dp[curLocation][0]+1 ):
                dp[newLocation][0]=dp[curLocation][0]+1
                dp[newLocation][1]+=1
                q.append(newLocation)
    return dp[end]
if __name__ == "__main__":
    result=BFS(*map(int,input().split()))
    print(result[0]-1)
    print(result[1])
