class Solution:
    def canJump(self, nums: List[int]) -> bool:
        curStart = 0
        curEnd   = nums[curStart]
        while True:
            if curEnd>=len(nums)-1: return True
            temp=max([ (i+nums[i],i) for i in range(curStart,curEnd+1)])
            nextStart=temp[1]
            nextEnd=temp[0]
            if nextStart>=len(nums)-1 or nextEnd>=len(nums)-1: return True
            if nextStart==curStart: return False
            curStart=nextStart
            curEnd=nextEnd
