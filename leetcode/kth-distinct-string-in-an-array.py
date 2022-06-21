import collections


class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        data = collections.OrderedDict()
        count = 0
        for key in arr:
            if key in data:
                data[key] += 1
            else:
                data[key] = 1
        for key, value in data.items():
            if value == 1:
                if count < k:
                    count += 1
                if count == k:
                    return key
        return ''
