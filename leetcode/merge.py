from collections import deque
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        temp=sorted(intervals)
        q=deque(temp[1:])
        curInterval=temp[0]
        answer=[]
        while q:
            if curInterval[1]>=q[0][0]:
                curInterval[1]=max(q[0][1],curInterval[1])
                q.popleft()
            else:
                answer.append(curInterval[:])
                curInterval=q.popleft()
        answer.append(curInterval)
        return answer
                
            
