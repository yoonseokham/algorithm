class Solution:
    def isPalindrome(self, s: str) -> bool:
        onlylower=[i.lower() for i in s if i.isalnum()]
        # print(onlylower)
        # start=0
        # end=len(onlylower)-1
        # while start<=end:
        #     if onlylower[start]!=onlylower[end]:
        #         return False
        #     start+=1
        #     end-=1
        # return True
        return onlylower==onlylower[::-1]
        
