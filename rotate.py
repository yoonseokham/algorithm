from collections import deque
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        temp=deque(nums)
        for i in range(k):
            temp.appendleft(temp.pop())
        for i,j in enumerate(temp):
            nums[i]=temp[i]
            
        """
        Do not return anything, modify nums in-place instead.
        """
        
