import sys
if __name__=="__main__":
    def mergeInterval(intervals):
        if not intervals: return []
        intervals.sort()
        start,end=intervals[0]
        temp=[]
        for i,j in intervals[1:]:
            if end>=i:end=max(end,j)
            else: temp.append((start,end));start=i;end=j
        temp.append((start,end))
        return temp
    n,m=map(int,input().split())
    leftToRight=[]
    rightToLeft=[]
    for _ in range(n):
        start,end=map(int,sys.stdin.readline().rstrip().split())
        leftToRight.append((start,end)) if start<end else rightToLeft.append((end,start))
    rightToLeft=mergeInterval(rightToLeft)
    sumed=0
    for i,j in rightToLeft:
        sumed+=j-i
    print(m+2*sumed)
