class Solution:
    def secondHighest(self, s: str) -> int:
        answer=set(int(i) for i in s if i.isdigit())
        if len(answer)<=1:
            return -1
        return sorted(list(answer),reverse=True)[1]
        
