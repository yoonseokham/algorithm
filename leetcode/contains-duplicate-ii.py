import collections
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        data = collections.defaultdict(list)
        for index, num in enumerate(nums):
            data[num].append(index)
        for key, value in data.items():
            for i in range(len(data[key])-1):
                if data[key][i+1] - data[key][i] <= k:
                    return True
        return False
