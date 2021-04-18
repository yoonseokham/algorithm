class Solution:
    def isPalindrome(self, x: int) -> bool:
        temp=str(x)
        temp=[i for i in temp]
        return temp==temp[::-1]
