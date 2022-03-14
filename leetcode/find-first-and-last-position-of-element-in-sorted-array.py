class Solution:
    def lowerBound(self, nums, target):
        start = 0
        end = len(nums) - 1
        answer = -1
        while start <= end:
            mid =  (start + end)//2
            if nums[mid] ==  target:
                answer = mid
                end = mid - 1
            elif nums[mid] <  target:
                start = mid + 1
            elif nums[mid] >  target:
                end = mid - 1
        return answer
    
    def upperBound(self, nums, target):
        start = 0
        end = len(nums) - 1
        answer = -1
        while start <= end:
            mid =  (start + end)//2
            if nums[mid] ==  target:
                answer = mid
                start = mid + 1
            elif nums[mid] <  target:
                start = mid + 1
            elif nums[mid] >  target:
                end = mid - 1
        return answer
    
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        return [self.lowerBound(nums,target),self.upperBound(nums,target)]
