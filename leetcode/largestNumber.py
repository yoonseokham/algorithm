class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        return str(int(''.join(sorted(list(map(str,nums)),key=lambda x:x*9 ,reverse=True))))
