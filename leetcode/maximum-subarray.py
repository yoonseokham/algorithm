class Solution:
    def isAllNegative(self, nums: List[int]) -> bool:
        return all(i<=0 for i in nums)
    
    def maxSubArray(self, nums: List[int]) -> int:
        if self.isAllNegative(nums):
            return max(nums)
        answer = 0
        sum = 0
        for i, num in enumerate(nums):
            if sum + num > 0:
                sum += num
                answer = max(answer, sum)
            else:
                answer = max(answer, sum)
                sum = 0
        return answer
