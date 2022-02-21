import collections
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counter = collections.defaultdict(int)
        for num in nums:
            counter[num] += 1
            if counter[num] > len(nums)//2:
                return num
