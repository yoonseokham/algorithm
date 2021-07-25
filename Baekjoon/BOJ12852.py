from collections import deque
if __name__ == '__main__':
    startNum=int(input())
    visitList=[0]*(startNum+1)
    def BFS():
        dp=[999999]*(startNum+1)
        dp[startNum]=1
        q=deque([startNum])
        while q:
            curNum=q.popleft()
            for i in range(3,0,-1):
                if curNum%i==0:
                    temp=curNum//i
                    if i==1:
                        temp-=1
                    if dp[temp]>dp[curNum]+1:
                        dp[temp]=dp[curNum]+1
                        visitList[temp]=curNum
                        q.append(temp)
        return dp[1]-1
    print(BFS())
    answer=[1]
    curNum=1
    while curNum!=startNum:
        answer.append(visitList[curNum])
        curNum=visitList[curNum]
    for i in reversed(answer):
        print(i,end=" ")