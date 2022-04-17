import collections
class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        start = 0
        end = 0
        
        letterCounter = collections.defaultdict(int)
        letterKey = set()
        answer = 0
        cur_string = collections.deque([])
        
        def addLetter(value):
            letterCounter[value]+=1
            letterKey.add(value)
            
        def deleteLetter(value):
            if letterCounter[value] == 1:
                letterKey.remove(value)
            letterCounter[value] -= 1
        
        def isAddable(value):
            return any([value in letterKey and len(letterKey) <=2,
                value not in letterKey and len(letterKey)<2])
                
        while(start<len(s) and end<len(s)):
            if isAddable(s[end]):
                addLetter(s[end])
                cur_string.append(s[end])
                answer = max(answer,len(cur_string))
                end += 1
            else:
                deleteLetter(s[start])
                cur_string.popleft()
                start += 1
        return answer
