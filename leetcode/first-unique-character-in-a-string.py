import collections
import types
class Solution:
    def firstUniqChar(self, s: str) -> int:
        data_dict = collections.OrderedDict()
        for index, value in enumerate(s):
            if value in data_dict:
                data_dict[value].count += 1
            else:
                data_dict[value] = types.SimpleNamespace(index = index , count = 1)          
        for key, data in data_dict.items():
            if data.count == 1:
                return data.index
        return -1
