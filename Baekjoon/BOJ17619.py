import sys
if __name__ == "__main__":
    MAX= (100001)
    parent=list(range(MAX))
    n,query=map(int,sys.stdin.readline().rstrip().split())
    lines=[(-1,-1)]
    for i in range(n):
        start,end,_=map(int,sys.stdin.readline().rstrip().split())
        lines.append((start,end,i+1))
    lines.sort()
    queries=[tuple(map(int,sys.stdin.readline().rstrip().split())) for _ in range(query)]
    def findParent(x:int)->int:
        if x==parent[x]: return x
        else:
            parent[x]=findParent(parent[x])
            return parent[x]
    def UnionXY(x:int,y:int)->None:
        x=findParent(x);y=findParent(y)
        if x>y:   parent[x]=y
        else: parent[y]=x
    def MergeInterval():
        curStart,curEnd,_=lines[1]
        for i in range(2,len(lines)):
            start,end,_=lines[i]
            if curEnd>=start:
                curEnd=max(curEnd,end)
                UnionXY(lines[i-1][2],lines[i][2])
            else: curStart=start;curEnd=end
    MergeInterval()
    for i,j in queries:
        parent[i]=findParent(i)
        parent[j]=findParent(j)
        print(1) if parent[i]==parent[j] else print(0)
