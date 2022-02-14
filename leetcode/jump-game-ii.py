class Solution:
    def jump(self, nums: List[int]) -> int:
        curIndex = 0
        answer = 0
        while curIndex < len(nums)-1:
            if curIndex + nums[curIndex] >= len(nums)-1:
                return answer + 1
            arr = [ (j+ nums[j],j) for j in range(curIndex + 1,min(curIndex + nums[curIndex]+1,len(nums)))]
            curIndex = max(arr)[1]
            print(arr)
            answer += 1
        return answer
