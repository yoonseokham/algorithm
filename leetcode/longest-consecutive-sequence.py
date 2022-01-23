import collections
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        isNum = collections.defaultdict(lambda:False)
        isVisit = collections.defaultdict(lambda:False)
        answer = 0
        
        def DFS(cur_num):
            nonlocal call_count
            call_count += 1
            isVisit[cur_num] = True
            for i in (-1,1):
                next_num = cur_num + i
                if isNum[next_num] and not isVisit[next_num]:
                    DFS(next_num)
        
        for num in nums:
            isNum[num] = True
        
        for num in nums:
            call_count = 0
            if not isVisit[num]:
                DFS(num)
                answer = max(answer,call_count)
        
        return answer
