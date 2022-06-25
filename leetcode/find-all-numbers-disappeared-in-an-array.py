class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        appear_nums = set(nums)
        answer = []
        for i in range(1,len(nums)+1):
            if i not in appear_nums:
                answer.append(i)
        return sorted(answer)
  
