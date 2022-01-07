class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        answer = 0 
        n = min(len(str) for str in strs)
        for i in range(n):
            check = set()
            for str in strs:
                check.add(str[i])
            if len(check) != 1:
                return strs[0][:i]
        return strs[0][:n]
        
