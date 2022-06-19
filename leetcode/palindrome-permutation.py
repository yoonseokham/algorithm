import collections


class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        count = collections.defaultdict(int)
        odd_count = 0
        for chr_s in s:
            count[chr_s] += 1
        for key, value in count.items():
            if value % 2:
                odd_count += 1
        if odd_count <= 1:
            return True
        return False
