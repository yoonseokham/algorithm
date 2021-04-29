class Solution:
    def expand(self,s:str,start:int,end:int)->str:
        while start>=0 and end<=len(s) and s[start]==s[end-1]:
            start-=1
            end+=1
        return s[start+1:end-1]
            
    def longestPalindrome(self, s: str) -> str:
        answer=s[0]
        for i in range(len(s)-1):
            answer=max(answer,self.expand(s,i,i+2),self.expand(s,i,i+3),key=len)
        return answer
