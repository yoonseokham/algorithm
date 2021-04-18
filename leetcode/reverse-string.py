class Solution:
    def reverseString(self, s: List[str]) -> None:
        #풀이 1 two pointer swap
        # start=0
        # end=len(s)-1
        # while start<=end:
        #     s[start],s[end]=s[end],s[start]
        #     start+=1
        #     end-=1
        #풀이 2 slice
        #s=s[::-1]
        #풀이 3 reverse
        s.reverse()
        
