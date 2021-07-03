from itertools import combinations
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        answer=[()]
        for i in range(1,len(nums)+1):
            for j in (combinations(nums,i)):
                answer.append(tuple(sorted(list(j))))
        return [list(i) for i in set(answer)]
