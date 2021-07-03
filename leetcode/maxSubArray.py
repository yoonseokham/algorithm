class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        answer=nums[0]
        currentSubSum=nums[0]
        for num in nums[1:]:
            answer=max(answer,currentSubSum)
            if currentSubSum<0:
                currentSubSum=num
            else:
                currentSubSum+=num
        return max(answer,currentSubSum)
