from collections import deque
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        answer=0
        s.sort()
        g.sort()
        g=deque(g)
        for i in s:
            if g and i>=g[0]:
                g.popleft()
                answer+=1
        return answer
            
