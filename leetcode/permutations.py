import copy
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        answer_list = []
        def backtrack(nums,visit=set(),answer=[]):
            if len(answer) == len(nums):
                answer_list.append(copy.deepcopy(answer))
                answer = []
            else:
                for num in nums:
                    if num not in visit:
                        answer.append(num)
                        visit.add(num)
                        backtrack(nums,visit,answer)
                        visit.remove(num)
                        answer.pop()
        backtrack(nums)
        return answer_list
            
