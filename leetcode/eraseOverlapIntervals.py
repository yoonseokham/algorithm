class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        temp=sorted(intervals,key=lambda x :(x[1],x[0]))
        cur=temp[0]
        erase=0
        for i in range(1,len(temp)):
            if cur[1]>temp[i][0]: erase+=1 
            else: cur=temp[i]
        return erase
            
