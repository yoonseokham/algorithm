def solution(n):
    chess=[[0]*n for i in range(n)]
    count=[0]
    queen=[]
    def killable(curIndex:int,index:int)->bool:
        for i,j in queen:
            if abs(curIndex-i)==abs(index-j) or j==index: return True
        return False
    def BackTrack(curIndex=0)->None:
        if curIndex>=n: count[0]+=1
        else:
            for i in range(n):
                if not killable(curIndex,i):
                    chess[curIndex][i]=1
                    queen.append((curIndex,i))
                    BackTrack(curIndex+1)
                    chess[curIndex][i]=0
                    queen.pop()
    BackTrack()
    return count[0]
