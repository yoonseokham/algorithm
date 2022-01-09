import itertools
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        answer = []
        for i in range(len(nums)+1):
            for element in map(list,itertools.combinations(nums,i)):
                answer.append(element)
        return answer
