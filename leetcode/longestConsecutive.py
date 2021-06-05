class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums=sorted(list(set(nums)))
        if not nums: return 0
        start=nums[0]
        maxConsequence=1
        answer=0
        for i in range(1,len(nums)):
            if nums[i]-start<=1:
                start=nums[i]
                maxConsequence+=1
            else:
                answer=max(answer,maxConsequence)
                start=nums[i]
                maxConsequence=1
        return max(answer,maxConsequence)
