class Solution:
    def expand(self,s:str,start:int,end:int,last:str)->str:
        last=s[start:end]
        start-=1
        end+=1
        if start<0 or end>len(s) or s[start]!=s[end-1]:
            return last
        elif s[start]==s[end-1]:
            return self.expand(s,start,end,last)
        else:
            return last
            
    def longestPalindrome(self, s: str) -> str:
        longest=s[0]
        if len(s)<2 or s[::-1]==s:
            return s
        for i in range(len(s)-1):
            if s[i:i+2]==''.join(reversed(s[i:i+2])):
                temp=self.expand(s,i,i+2,s[i:i+2])
                if len(temp)>len(longest):
                    longest=temp
        for i in range(len(s)-2):
            if s[i:i+3]==''.join(reversed(s[i:i+3])):
                temp=self.expand(s,i,i+3,s[i:i+3])
                if len(temp)>len(longest):
                    longest=temp
        return longest

