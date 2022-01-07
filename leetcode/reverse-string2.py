class Solution:
    def reverseString(self, s: List[str]) -> None:
        def converter(left,right):
            if left<right:
                s[left],s[right] = s[right],s[left]
                converter(left+1,right-1)
        converter(0,len(s)-1)        
