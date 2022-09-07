import collections
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        info = collections.namedtuple('info','value index')
        my_nums = [ info(value,index) for index, value in enumerate(nums)]
        my_nums.sort(key=lambda x:x.value)
        start = 0
        end = len(nums) - 1
        while start < end:
            if my_nums[start].value + my_nums[end].value == target:
                return sorted([my_nums[start].index, my_nums[end].index])
            elif my_nums[start].value + my_nums[end].value > target:
                end -= 1
            else:
                start += 1
