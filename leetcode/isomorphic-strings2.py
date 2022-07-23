import collections


class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s_data = collections.defaultdict(list)
        t_data = collections.defaultdict(list)

        for data, i in [(s_data, s), (t_data, t)]:
            for index, value in enumerate(i):
                data[value].append(index)

        s_normalize = sorted([i for _, i in s_data.items()])
        t_normalize = sorted([i for _, i in t_data.items()])
        if t_normalize == s_normalize:
            return True
        return False
      
