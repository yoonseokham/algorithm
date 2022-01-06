class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start = 0
        end = 0
        answer = 0
        SubstringElement = set()
        while end < len(s):
            if s[end] not in SubstringElement:
                SubstringElement.add(s[end])
                end += 1
                answer = max(answer,end-start)
            else:
                SubstringElement.remove(s[start])
                start += 1
        return answer
        
