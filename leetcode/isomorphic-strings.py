import collections
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s_data = collections.defaultdict(bool)
        t_data = collections.defaultdict(bool)
        
        result = list(zip(s,t))

        for i,j in result:
            if not s_data[i]:
                s_data[i] = j
            elif s_data[i] != j:
                return False
            if not t_data[j]:
                t_data[j] = i
            elif t_data[j] != i:
                return False
        return True
