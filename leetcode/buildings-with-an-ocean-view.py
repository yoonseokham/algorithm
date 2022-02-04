import collections
class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        answer = collections.deque([])
        current_blocking_height = 0
        for i in range(len(heights)-1,-1,-1):
            if current_blocking_height < heights[i]:
                answer.appendleft(i)
                current_blocking_height = heights[i]
        return answer
