import itertools
import collections
class Solution:
    def lenCalculate(self, s, combi):
        isUsed = collections.defaultdict(bool)
        start = 0
        end = len(s)
        for i in combi:
            if isUsed[s[start:i]] or s[start:i] == '':
                return 0
            else:
                isUsed[s[start:i]] = True
            start = i
        if isUsed[s[i:end]] or s[i:end] == '': 
            return 0
        isUsed[s[i:end]] = True
        return len(isUsed)
    
    def maxUniqueSplit(self, s: str) -> int:
        index = list(range(len(s)))
        answer = 1
        for i in range(1,len(s)+1):
            for combi in itertools.combinations(index,i):
                answer = max(answer,self.lenCalculate(s,combi))
        return answer
