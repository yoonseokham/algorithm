from collections import defaultdict
import sys
def findSum(accumulateSum:list,answerSpace:list,target:int)->int:
    start=0
    end=len(answerSpace)-1
    answer=-1
    while start<=end:
        mid=(start+end)//2
        if answerSpace[mid]<target:
            start=mid+1
            answer=max(mid,answer)
        elif answerSpace[mid]>=target:
            end=mid-1
    if answer==-1: return 0
    return accumulateSum[answer]
if __name__ == "__main__":
    colorGather=defaultdict(list)
    accumulateSum=defaultdict(list)
    ballInfo=defaultdict(tuple)
    ball=[]
    for i in range(1,int(input())+1):
        color,scale=map(int,sys.stdin.readline().rstrip().split())
        colorGather[color].append(scale)
        ballInfo[i]=(color,scale)
        ball.append(scale)
    ball.sort()
    accBall=[0]*len(ball)
    accBall[0]=ball[0]
    for i in range(1,len(ball)):
        accBall[i]=ball[i]+accBall[i-1]
    for i in colorGather.keys():
        colorGather[i].sort()
        accumulateSum[i]=[0]*len(colorGather[i])
        accumulateSum[i][0]=colorGather[i][0]
        for j in range(1,len(colorGather[i])):
            accumulateSum[i][j]=accumulateSum[i][j-1]+colorGather[i][j]
    for i,(color,scale) in ballInfo.items():
        localSum=findSum(accBall,ball,scale)-findSum(accumulateSum[color],colorGather[color],scale)
        # for j in colorGather.keys():
        #     if color!=j:
        #         localSum+=findSum(accumulateSum[j],colorGather[j],scale)
        print(localSum)
