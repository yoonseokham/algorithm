class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        curTime=0
        wait=0
        for i in customers:
            start,dur=i
            if curTime<=start:
                curTime=start+dur
                wait+=dur
            else:
                curTime+=dur
                wait+=curTime-start
        return wait/len(customers)
